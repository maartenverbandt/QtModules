#include "qshowthreadinginfoaction.h"

QShowThreadingInfoAction::QShowThreadingInfoAction(QRobotWindow *window, QObject *parent) :
    QShowDockAction("threading info", window, parent)
{
    // do nothing
}

void QShowThreadingInfoAction::showDock()
{
    QDockWidget *dock = new QDockWidget("threading info", _window);
    QThreadInfoDataNodeWidget *w = new QThreadInfoDataNodeWidget(dock);
    _window->robot()->connectTo(w);
    dock->setAllowedAreas(Qt::BottomDockWidgetArea | Qt::TopDockWidgetArea);
    dock->setWidget(w->w());
    _window->addDockWidget(Qt::BottomDockWidgetArea, dock);
}


