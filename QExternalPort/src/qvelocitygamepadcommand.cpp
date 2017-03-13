#include "qvelocitygamepadcommand.h"

QVelocityGamepadCommand::QVelocityGamepadCommand(QObject *parent) :
    QGamepadCommand(parent)
{
    add("vx");
    add("vy");
    add("vz");
}

mavlink_velocity_cmd_t QVelocityGamepadCommand::getVelocityCmdPacket()
{
    mavlink_velocity_cmd_t velocity_cmd;
    velocity_cmd.vx = value("vx");
    velocity_cmd.vy = value("vy");
    velocity_cmd.vz = value("vz");
    velocity_cmd.vxFF = 0;
    velocity_cmd.vyFF = 0;
    velocity_cmd.vzFF = 0;
}

QVariant QVelocityGamepadCommand::getPacket()
{
    QVariant velocity_cmd;
    velocity_cmd.setValue(getVelocityCmdPacket());
    return velocity_cmd;
}
