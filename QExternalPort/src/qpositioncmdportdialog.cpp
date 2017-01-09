#include "qpositioncmdportdialog.h"

QPositionCmdPortDialog::QPositionCmdPortDialog(QWidget *parent) :
    QExternalPortDialog("position command",parent),
    _file_port(new QPositionCmdFilePort(this)),
    _udp_port(new QPositionCmdUdpPort(this))
{
    addPort(_file_port,"file");
    addPort(_udp_port,"UDP");
}

mavlink_position_cmd_t QPositionCmdPortDialog::getPositionCmdPacket()
{
    QVariant position_cmd = getPacket();
    return position_cmd.value<mavlink_position_cmd_t>();
}

void QPositionCmdPortDialog::timerEvent(QTimerEvent *)
{
    mavlink_position_cmd_t cmd = getPositionCmdPacket();
    emit positionCmdPacket(cmd);
}
