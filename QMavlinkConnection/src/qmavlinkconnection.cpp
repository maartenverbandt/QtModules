#include "qmavlinkconnection.h"

#define IO_BUFFER_SIZE  1024

QMavlinkConnection::QMavlinkConnection(QObject *parent, QIODevice *io, QString name, serial_t serial_type):
    QObject(parent),
    _io(io),
    _serial_type(serial_type),
    _name(name),
    _packet_count(0),
    _packet_drops(0),
    _timer_packet_count(0),
    _suspend_action("suspend",this),
    _info_action("info",this),
    _log_action("log",this),
    _quicklog_action("quick log",this)
{    
    //connect iodevice
    QObject::connect(_io, &QIODevice::readyRead, this, &QMavlinkConnection::mavlinkParseData);

    //configure actions
    _suspend_action.setCheckable(true);
    _suspend_action.setChecked(false);
    QObject::connect(&_suspend_action, &QAction::toggled, this, &QMavlinkConnection::toggleSuspend);
    QObject::connect(&_info_action,&QAction::triggered,this,&QMavlinkConnection::connectionInfoDialog);
    _log_action.setCheckable(true);
    _quicklog_action.setCheckable(true);
    QObject::connect(&_log_action, &QAction::triggered, &_quicklog_action, &QAction::setChecked);
    QObject::connect(&_quicklog_action, &QAction::triggered, &_log_action, &QAction::setChecked);
    QObject::connect(&_log_action, &QAction::triggered, this, &QMavlinkConnection::logActionCallback);
    QObject::connect(&_quicklog_action, &QAction::triggered, this, &QMavlinkConnection::quicklogActionCallback);
}

QMavlinkConnection::~QMavlinkConnection()
{
    _io->close();
}

QString QMavlinkConnection::name()
{
    return _name;
}

QMavlinkConnection::serial_t QMavlinkConnection::type()
{
    return _serial_type;
}

mavlink_message_t QMavlinkConnection::msg()
{
    return _msg;
}

unsigned long QMavlinkConnection::packetCount()
{
    return _packet_count;
}

unsigned long QMavlinkConnection::packetDrops()
{
    return _packet_drops;
}

unsigned int QMavlinkConnection::getRobotID()
{
    return _robot_id;
}

unsigned int QMavlinkConnection::getRobotType()
{
    return _robot_type;
}

QString QMavlinkConnection::getMenuName()
{
    return _name;
}

void QMavlinkConnection::setPending()
{
    //check the heartbeat
    QObject::connect(this,&QMavlinkConnection::mavlinkMsgReceived,this,&QMavlinkConnection::checkHeartbeat);

    //activate single shot timer
    _timer.setSingleShot(true);
    _timer.setInterval(5000);
    QObject::connect(&_timer, &QTimer::timeout, this, &QMavlinkConnection::timeout);
}

void QMavlinkConnection::setConnected()
{
    _timer.stop(); //prevent the timeout event
    QObject::disconnect(this,&QMavlinkConnection::mavlinkMsgReceived, this, &QMavlinkConnection::checkHeartbeat); //no heartbeats
}

void QMavlinkConnection::setSuspended()
{
    _io->close();
    qDebug() << "connection suspended";
}

void QMavlinkConnection::setActive()
{
    _io->open(QIODevice::ReadWrite);
    qDebug() << "connection activated";
}

QAction *QMavlinkConnection::getSuspendAction()
{
    return &_suspend_action;
}

QAction *QMavlinkConnection::getQuicklogAction()
{
    return &_quicklog_action;
}

QMenu *QMavlinkConnection::constructMenu(const QString menu_title, QWidget* parent)
{
    QMenu *menu = new QMenu(menu_title, parent); //automatically deleted if connection is deleted
    menu->addAction(&_suspend_action);
    menu->addSeparator();
    menu->addAction(&_info_action);

    return menu;
}

QMenu *QMavlinkConnection::constructMenu(QWidget *parent)
{
    //set up menu
    QString menu_title;
    switch(type()){
        case QMavlinkConnection::SERIAL_USB:
            menu_title = "USB";
            break;
        case QMavlinkConnection::SERIAL_BT:
            menu_title = "BT";
            break;
        case QMavlinkConnection::SERIAL_UDP:
            menu_title = "UDP";
            break;
        default:
            menu_title = "unknown:";
    }

    menu_title += ": " + name();
    return constructMenu(menu_title, parent);
}

void QMavlinkConnection::mavlinkMsgSend(mavlink_message_t msg)
{
    char buffer[128];
    int bytes;

    bytes = mavlink_msg_to_send_buffer((uint8_t*)buffer, &msg);
    _io->write((char*)buffer, bytes);
}

void QMavlinkConnection::checkHeartbeat(mavlink_message_t msg)
{
    if(msg.msgid == MAVLINK_MSG_ID_HEARTBEAT){
        mavlink_heartbeat_t heartbeat;
        mavlink_msg_heartbeat_decode(&msg, &heartbeat);
        _robot_id = msg.sysid;
        _robot_type = heartbeat.type;

        static_cast<QConnectionCoordinator*>(parent())->connected(this);
        setConnected();
    }
}

void QMavlinkConnection::timeout()
{
    static_cast<QConnectionCoordinator*>(parent())->timedOut(this);
    qDebug() << this->name() << "timed out.";
}

void QMavlinkConnection::mavlinkParseData()
{
    QByteArray data = _io->readAll();
    for(int k=0;k<data.length();k++){
        if(mavlink_parse_char(0, data.at(k), &_msg, &_status)){
            _packet_count++;
            emit mavlinkMsgReceived(_msg);
            //qDebug() << "packet_count: " + QString::number(_packet_count);
        }
        _packet_drops += _status.packet_rx_drop_count;
    }
}

void QMavlinkConnection::connectionInfoDialog()
{
    QMavlinkConnectionInfoDialog *dialog = new QMavlinkConnectionInfoDialog();
    QObject::connect(this,&QMavlinkConnection::mavlinkMsgReceived,dialog,&QMavlinkConnectionInfoDialog::mavlinkMsgReceived);
    QObject::connect(this,&QMavlinkConnection::destroyed,dialog,&QMavlinkConnectionInfoDialog::deleteLater);
    dialog->show();
}

void QMavlinkConnection::logActionCallback(bool checked)
{
    logCallback(checked,false);
}

void QMavlinkConnection::quicklogActionCallback(bool checked)
{
    logCallback(checked,true);
}

void QMavlinkConnection::toggleSuspend()
{
    if(_suspend_action.isChecked()){
        setSuspended();
    } else {
        setActive();
    }
}

void QMavlinkConnection::logCallback(bool checked, bool autoname)
{
    if(checked){
        //determine filename
        QString filename = QDir::homePath() + "/logs/log_" + QDateTime::currentDateTime().toString("MM_dd_hh_mm") + ".log";
        if(!autoname){
            filename = QFileDialog::getSaveFileName(0, "Save Log", filename, ".log");
        }

        //make logger with that filename
        QMavlinkConnectionLogger* logger = new QMavlinkConnectionLogger(filename,this);
        QObject::connect(this,&QMavlinkConnection::closeLog,logger,&QMavlinkConnectionLogger::deleteLater);
        QObject::connect(this,&QMavlinkConnection::mavlinkMsgReceived,logger,&QMavlinkConnectionLogger::mavlinkMsgReceived);
        QObject::connect(logger,&QMavlinkConnectionLogger::mavlinkMsgSend,this,&QMavlinkConnection::mavlinkMsgSend);
    } else {
        //close existing log via callback
        emit closeLog();
    }
}
