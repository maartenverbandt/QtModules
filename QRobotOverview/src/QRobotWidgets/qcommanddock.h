#ifndef QCOMMANDDOCK_H
#define QCOMMANDDOCK_H

#include <qrobotwindowdock.h>
#include <qcommandwidget.h>

class QCommandDock : public QRobotWindowDock
{
    Q_OBJECT
public:
    explicit QCommandDock(QRobotWindow *window);

private:
    QCommandWidget *_command_widget;

};

#endif // QCOMMANDDOCK_H
