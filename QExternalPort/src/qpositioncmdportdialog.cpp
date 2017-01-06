#include "qpositioncmdportdialog.h"

QPositionCmdPortDialog::QPositionCmdPortDialog(QWidget *parent) :
    QExternalPortDialog("position command",parent),
    _file_port(new QPositionCmdFilePort(this))
{
    addPort(_file_port,"file");
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
