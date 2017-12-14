#include "qrobotwindowdock.h"
#include <qrobotwindow.h>

QRobotWindowDock::QRobotWindowDock(const QString& text, QRobotWindow *window) :
    QDockWidget(text,window), _window(window), _show(new QAction(text,window))
{
    setObjectName(text);
    close();
    QObject::connect(_show, &QAction::triggered, this, &QRobotWindowDock::show);
    QObject::connect(_show, &QAction::triggered, this, &QRobotWindowDock::on_show);
    QObject::connect(window, &QRobotWindow::closing, this, &QRobotWindowDock::close);
    QObject::connect(window, &QRobotWindow::closing, this, &QRobotWindowDock::on_close);
}

QAction *QRobotWindowDock::showAction()
{
    return _show;
}
