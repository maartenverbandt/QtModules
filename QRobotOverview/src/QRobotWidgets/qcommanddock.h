#ifndef QCOMMANDDOCK_H
#define QCOMMANDDOCK_H

#include <qrobotwindowdock.h>
#include <qrobotcommandwidget.h>

class QCommandDock : public QRobotWindowDock
{
    Q_OBJECT
public:
    explicit QCommandDock(QRobotWindow *window);
    QRobotCommandWidget *datanode();

private:
    QRobotCommandWidget *_command_widget;

protected slots:
    virtual void on_show();
    virtual void on_close();

};

#endif // QCOMMANDDOCK_H
