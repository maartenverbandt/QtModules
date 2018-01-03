#ifndef QCOMMANDDOCK_H
#define QCOMMANDDOCK_H

#include <qrobotwindowdock.h>
#include <qcommandwidget.h>

class QCommandDock : public QRobotWindowDock
{
    Q_OBJECT
public:
    explicit QCommandDock(QRobotWindow *window);
    QCommandWidget *datanode();

private:
    QCommandWidget *_command_widget;

protected slots:
    virtual void on_show();
    virtual void on_close();

};

#endif // QCOMMANDDOCK_H
