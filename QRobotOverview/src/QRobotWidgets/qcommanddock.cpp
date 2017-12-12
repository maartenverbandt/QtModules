#include "qshowcommandwidgetaction.h"

QShowCommandWidgetAction::QShowCommandWidgetAction(QRobotWindow *window, QObject *parent) :
    QShowDockAction("commands", window, parent)
{
    // do nothing
}

void QShowCommandWidgetAction::showDock()
{
    QDockWidget *dock = new QDockWidget("command", _window);
    QCommandWidget *w = _window->command(dock);

    // connect all connections to the widget
    QListIterator<QSerialProtocol *> i(_window->robot()->connections());
    while(i.hasNext()){
        w->transmitTo(i.next());
    }

    dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    dock->setWidget(w);
    _window->addDockWidget(Qt::RightDockWidgetArea, dock);
}
