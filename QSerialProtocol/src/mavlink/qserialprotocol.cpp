#include <qserialprotocol.h>

QSerialProtocol::QSerialProtocol(QIODevice *io, QObject *parent) :
    QDataNode(parent), _packet_count(0), _packet_drops(0), _io(io)
{
    QObject::connect(_io, &QIODevice::readyRead, this, &QSerialProtocol::decode);
}

void QSerialProtocol::decode()
{
    QByteArray b = _io->readAll();
    for(int k=0;k<b.length();k++){
        if(mavlink_parse_char(0, b.at(k), &_msg, &_status)){
            _packet_count++;
            switch(_msg.msgid) {
                case MAVLINK_MSG_ID_HEARTBEAT: {
                    heartbeat_t heartbeat;
                    mavlink_msg_heartbeat_decode(&_msg,&heartbeat);
                    emit transmit(heartbeat);
                    break; }
                case MAVLINK_MSG_ID_EVENT: {
                    event_t event;
                    mavlink_msg_event_decode(&_msg,&event);
                    emit transmit(event);
                    break; }
                case MAVLINK_MSG_ID_PARAM_INT: {
                    param_int_t param_int;
                    mavlink_msg_param_int_decode(&_msg,&param_int);
                    emit transmit(param_int);
                    break; }
                case MAVLINK_MSG_ID_PARAM_FLOAT: {
                    param_float_t param_float;
                    mavlink_msg_param_float_decode(&_msg,&param_float);
                    emit transmit(param_float);
                    break; }
                default: {
                    //qDebug() << "Unknown msg id: cannot decode.";
                }
            }
        }
        _packet_drops += _status.packet_rx_drop_count;
    }
}

void QSerialProtocol::encode(mavlink_message_t msg)
{
    QByteArray b(128,0);
    int bytes = mavlink_msg_to_send_buffer((uint8_t*)(b.data()), &msg);
    b.truncate(bytes);
    _io->write(b);
}

void QSerialProtocol::receive(heartbeat_t heartbeat)
{
    mavlink_message_t msg;
    mavlink_msg_heartbeat_encode(0,0,&msg,&heartbeat);
    encode(msg);
}

void QSerialProtocol::receive(event_t event)
{
    mavlink_message_t msg;
    mavlink_msg_event_encode(0,0,&msg,&event);
    encode(msg);
}

void QSerialProtocol::receive(param_int_t param_int)
{
    mavlink_message_t msg;
    mavlink_msg_param_int_encode(0,0,&msg,&param_int);
    encode(msg);
}

void QSerialProtocol::receive(param_float_t param_float)
{
    mavlink_message_t msg;
    mavlink_msg_param_float_encode(0,0,&msg,&param_float);
    encode(msg);
}
int QSerialProtocol::packetCount()
{
    return _packet_count;
}

int QSerialProtocol::packetDrops()
{
    return _packet_drops;
}

