#include "qpositioncmdudpport.h"

QPositionCmdUdpPort::QPositionCmdUdpPort(QObject *parent):
    QObject(parent),
    _udp_port(new QUdpPortWidget(MAVLINK_MSG_ID_POSITION_CMD_LEN,0))
{

}

mavlink_position_cmd_t QPositionCmdUdpPort::getPositionCmdPacket()
{
    mavlink_position_cmd_t position_cmd;
    QByteArray packet = _udp_port->readLine();

    if(packet.length()>0){
        memcpy((char*)(&position_cmd),packet.data(),sizeof(position_cmd));
    } else {
        position_cmd.x = 0;
        position_cmd.y = 0;
        position_cmd.z = 0;
        position_cmd.xFF = 0;
        position_cmd.yFF = 0;
        position_cmd.zFF = 0;
    }

    return position_cmd;
}

QVariant QPositionCmdUdpPort::getPacket()
{
    QVariant position_cmd;
    position_cmd.setValue(getPositionCmdPacket());
    return position_cmd;
}

QWidget *QPositionCmdUdpPort::getWidget()
{
    return _udp_port;
}


