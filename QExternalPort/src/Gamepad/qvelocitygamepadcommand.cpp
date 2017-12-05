#include "qvelocitygamepadcommand.h"

QVelocityGamepadCommand::QVelocityGamepadCommand(QWidget *parent) :
    QGamepadCommand("Velocity",parent)
{
    _cmd_widget->add("vx");
    _cmd_widget->add("vy");
    _cmd_widget->add("vz");
}

void QVelocityGamepadCommand::transmit_packet()
{
    velocity_cmd_t velocity_cmd;
    velocity_cmd.vx = _cmd_widget->value("vx")*1000;
    velocity_cmd.vy = _cmd_widget->value("vy")*1000;
    velocity_cmd.vz = _cmd_widget->value("vz")*1000;
    velocity_cmd.vxFF = 0;
    velocity_cmd.vyFF = 0;
    velocity_cmd.vzFF = 0;

    transmit(velocity_cmd);
}
