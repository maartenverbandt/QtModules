#include "qrobotwindowdock.h"

QRobotWindowDock::QRobotWindowDock(const QString& text, QRobotWindow *window) :
    QDockWidget(text,window), _show(new QAction(text,window))
{
    setObjectName(text);
    QObject::connect(_show, &QAction::triggered, this, &QRobotWindowDock::show);
    QObject::connect(window, &QRobotWindow::closing, this, &QRobotWindowDock::close);
}

QAction *QRobotWindowDock::showAction()
{
    return _show;
}

/*void QRobotWindowDock::saveState()
{

}

void QRobotWindowDock::restoreState()
{

}*/

/*void QShowDockAction::setAllowedAreas(Qt::DockWidgetArea areas)
{
    _dock->setAllowedAreas(areas);
}

void QShowDockAction::showDock()
{
    _dock->setWidget(_);
}*/
