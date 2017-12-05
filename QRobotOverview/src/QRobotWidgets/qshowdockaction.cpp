#include "qshowdockaction.h"

QShowDockAction::QShowDockAction(const QString& text, QRobotWindow *window, QObject *parent) :
    QAction(text, parent), _window(window)
{
    QObject::connect(this, &QShowDockAction::triggered, this, &QShowDockAction::showDock);
}
