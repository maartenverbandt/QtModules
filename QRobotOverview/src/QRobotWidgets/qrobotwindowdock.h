#ifndef QSHOWDOCKACTION_H
#define QSHOWDOCKACTION_H

#include <QAction>
#include <QDockWidget>
#include <qrobotwindow.h>

class QShowDockAction : public QAction
{
public:
    explicit QShowDockAction(const QString& text, QRobotWindow *window, QObject *parent = 0);

protected:
    QRobotWindow *_window;

protected slots:
    virtual void showDock() = 0;

};

#endif // QSHOWDOCKACTION_H
