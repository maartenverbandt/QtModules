#include "qvelocitygamepadcommand.h"

QVelocityGamepadCommand::QVelocityGamepadCommand(QGamepadInputWidget *parent) :
    _cmd_widget(new QCommandMapWidget(parent))
{
    _cmd_widget->add("vx");
    _cmd_widget->add("vy");
    _cmd_widget->add("vz");
    _cmd_widget->setup();
}

mavlink_velocity_cmd_t QVelocityGamepadCommand::getVelocityCmdPacket()
{
    mavlink_velocity_cmd_t velocity_cmd;
    velocity_cmd.vx = _cmd_widget->value("vx")*1000;
    velocity_cmd.vy = _cmd_widget->value("vy")*1000;
    velocity_cmd.vz = _cmd_widget->value("vz")*1000;
    velocity_cmd.vxFF = 0;
    velocity_cmd.vyFF = 0;
    velocity_cmd.vzFF = 0;

    return velocity_cmd;
}

QVariant QVelocityGamepadCommand::getPacket()
{
    QVariant velocity_cmd;
    velocity_cmd.setValue(getVelocityCmdPacket());
    return velocity_cmd;
}

QWidget *QVelocityGamepadCommand::getWidget()
{
    return _cmd_widget;
}

bool QVelocityGamepadCommand::enabled()
{
    return _cmd_widget->enabled();
}

void QVelocityGamepadCommand::reset()
{
    //do nothing
}
