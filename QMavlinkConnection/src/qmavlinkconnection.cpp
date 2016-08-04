#include "qmavlinkconnection.h"

#define IO_BUFFER_SIZE  1024

QMavlinkConnection::QMavlinkConnection(QObject *parent, QIODevice *io, QString name, serial_t serial_type):
    QObject(parent),
    _io(io),
    _name(name),
    _serial_type(serial_type),
    _packet_count(0),
    _packet_drops(0),
    _timer_packet_count(0),
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

    //activate single shot timer
    _timer.setSingleShot(true);
    QObject::connect(&_timer, SIGNAL(timeout()), this, SLOT(checkTimeout()));
}

QMavlinkConnection::~QMavlinkConnection()
{
    _io->close();
}

QString QMavlinkConnection::name()
{
    return _name;
}

serial_t QMavlinkConnection::type()
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

void QMavlinkConnection::mavlinkMsgSend(mavlink_message_t msg)
{
    char buffer[128];
    int bytes;

    bytes = mavlink_msg_to_send_buffer((uint8_t*)buffer, &msg);
    _io->write((char*)buffer, bytes);
}

void QMavlinkConnection::mavlinkParseData()
{
    QByteArray data = _io->readAll();
    mavlinkParseData(&data);
}

void QMavlinkConnection::mavlinkParseData(QByteArray* data)
{
    for(unsigned int k=0;k<data->length();k++){
        if(mavlink_parse_char(0, data->at(k), &_msg, &_status)){
            _packet_count++;
            emit mavlinkMsgReceived(_msg);
            //qDebug() << "packet_count: " + QString::number(_packet_count);
        }
        _packet_drops += _status.packet_rx_drop_count;
    }
}

void QMavlinkConnection::checkTimeout()
{
    //qDebug() << "bytes available: " + QString::number(_io->bytesAvailable());
    emit mavlinkConnected(_timer_packet_count<_packet_count);
}

void QMavlinkConnection::checkConnection()
{
    _timer_packet_count = _packet_count;
    _timer.start(3000);
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
