#include "qshowconnectioninfoaction.h"

QShowConnectionInfoAction::QShowConnectionInfoAction(QDataNode* connection, QRobotWindow *window, QObject *parent) :
    QShowDockAction("info", window, parent), _connection(connection)
{
    //do nothing
}

void QShowConnectionInfoAction::showDock()
{
    QDockWidget *dock = new QDockWidget(_connection->objectName() + " info", _window);
    QConnectionInfoDataNodeWidget *w = new QConnectionInfoDataNodeWidget(dock);
    _window->robot()->connectTo(w);
    dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    dock->setWidget(w->w());
    _window->addDockWidget(Qt::RightDockWidgetArea, dock);
}
