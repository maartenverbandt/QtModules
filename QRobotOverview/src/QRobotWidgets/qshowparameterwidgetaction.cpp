#include "qshowparameterwidgetaction.h"

QShowParameterWidgetAction::QShowParameterWidgetAction(QRobotWindow *window, QObject *parent) :
    QShowDockAction("parameters", window, parent)
{
    // do nothing
}

void QShowParameterWidgetAction::showDock()
{
    QDockWidget *dock = new QDockWidget("parameters", _window);
    QParameterDataNodeWidget *w = new QParameterDataNodeWidget(dock);
    _window->robot()->connectTo(w);
    dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    dock->setWidget(w->w());
    _window->addDockWidget(Qt::RightDockWidgetArea, dock);
}
