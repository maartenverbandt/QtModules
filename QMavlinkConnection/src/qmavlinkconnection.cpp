#include "qmavlinkconnection.h"

#define IO_BUFFER_SIZE  1024

QMavlinkConnection::QMavlinkConnection(QObject *parent, QIODevice *io, QString name, serial_t serial_type):
    QObject(parent),
    _io(io),
    _name(name),
    _serial_type(serial_type),
    _packet_count(0),
    _packet_drops(0),
    _disconnect_action("disconnect",this),
    _reconnect_action("reconnect",this),
    _info_action("info",this),
    _log_action("log",this),
    _quicklog_action("quick log",this)
{
    //connect iodevice
    QObject::connect(_io, SIGNAL(readyRead()), this, SLOT(mavlinkParseData()));

    //configure actions
    QObject::connect(&_disconnect_action,SIGNAL(triggered()),this,SLOT(deleteLater()));
    //QObject::connect(&_reconnect_action,SIGNAL(triggered()),this,SLOT(reconnect()));
    QObject::connect(&_info_action,SIGNAL(triggered()),this,SLOT(connectionInfoDialog()));
    _log_action.setCheckable(true);
    _quicklog_action.setCheckable(true);
    QObject::connect(&_log_action, SIGNAL(triggered(bool)), &_quicklog_action, SLOT(setChecked(bool)));
    QObject::connect(&_quicklog_action, SIGNAL(triggered(bool)), &_log_action, SLOT(setChecked(bool)));
    QObject::connect(&_log_action, SIGNAL(triggered(bool)), this, SLOT(logActionCallback(bool)));
    QObject::connect(&_quicklog_action, SIGNAL(triggered(bool)), this, SLOT(quicklogActionCallback(bool)));
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
    QObject::connect(this,SIGNAL(mavlinkMsgReceived(mavlink_message_t)),this,SLOT(checkHeartbeat(mavlink_message_t)));

    //activate single shot timer
    _timer.setSingleShot(true);
    QObject::connect(&_timer, SIGNAL(timeout()), this, SLOT(timeout()));
}

void QMavlinkConnection::setConnected()
{
    _timer.stop(); //prevent the timeout event
    QObject::disconnect(this,SIGNAL(mavlinkMsgReceived(mavlink_message_t)),this,SLOT(checkHeartbeat(mavlink_message_t))); //no heartbeats
}

QAction *QMavlinkConnection::getQuicklogAction()
{
    return &_quicklog_action;
}

QMenu *QMavlinkConnection::constructMenu(const QString menu_title, QWidget* parent)
{
    QMenu *menu = new QMenu(menu_title, parent); //automatically deleted if connection is deleted
    menu->addAction(&_disconnect_action);
    menu->addSeparator();
    menu->addAction(&_info_action);
    menu->addAction(&_log_action);

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

    QMenu *menu = new QMenu(menu_title, parent); //automatically deleted if connection is deleted
    menu->addAction(&_reconnect_action);
    menu->addAction(&_disconnect_action);
    menu->addSeparator();
    menu->addAction(&_info_action);

    return menu;
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
    }
}

void QMavlinkConnection::timeout()
{
    static_cast<QConnectionCoordinator*>(parent())->timedout(this);
}

void QMavlinkConnection::mavlinkParseData()
{
    QByteArray data = _io->readAll();
    for(unsigned int k=0;k<data.length();k++){
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
    QObject::connect(this,SIGNAL(mavlinkMsgReceived(mavlink_message_t)),dialog,SLOT(mavlinkMsgReceived(mavlink_message_t)));
    QObject::connect(this,SIGNAL(destroyed()),dialog,SLOT(deleteLater()));
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
        QObject::connect(this,SIGNAL(closeLog()),logger,SLOT(deleteLater()));
        QObject::connect(this, SIGNAL(mavlinkMsgReceived(mavlink_message_t)), logger, SLOT(mavlinkMsgReceived(mavlink_message_t)));
        QObject::connect(logger, SIGNAL(mavlinkMsgSend(mavlink_message_t)), this, SLOT(mavlinkMsgSend(mavlink_message_t)));
    } else {
        //close existing log via callback
        emit closeLog();
    }
}
