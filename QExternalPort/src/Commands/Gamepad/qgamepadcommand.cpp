#include "qgamepadcommand.h"

QGamepadCommand::QGamepadCommand(QString name, QWidget *parent) :
    _cmd_widget(new QCommandMapWidget(name,parent))
{
    _cmd_widget->setup();
}

QWidget *QGamepadCommand::getWidget()
{
    return _cmd_widget;
}

QCommandMapWidget *QGamepadCommand::cmdWidget()
{
    return _cmd_widget;
}

bool QGamepadCommand::enabled()
{
    return _cmd_widget->enabled();
}

void QGamepadCommand::reset()
{
    //do nothing
}
