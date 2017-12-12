#include "qcommanddock.h"

QCommandDock::QCommandDock(QRobotWindow *window) :
    QRobotWindowDock("commands", window)
{
    _command_widget = window->command(this);
    _command_widget->restoreState(window->robot()->objectName());
    QListIterator<QSerialProtocol *> i(window->robot()->connections());
    while(i.hasNext()){
        _command_widget->transmitTo(i.next());
    }
    setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    setWidget(_command_widget);
    window->addDockWidget(Qt::RightDockWidgetArea, this);
}

void QCommandDock::on_show()
{
    _command_widget->restoreState(_window->group());
}

void QCommandDock::on_close()
{
    _command_widget->saveState(_window->group());
}
