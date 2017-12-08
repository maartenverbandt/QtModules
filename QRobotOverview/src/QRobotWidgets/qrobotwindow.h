#ifndef QROBOTWINDOW_H
#define QROBOTWINDOW_H

#include <QStatusBar>
#include <QMenuBar>
#include <QLabel>
#include <qstackedwindow.h>
#include <qgpiodatanodewidget.h>
#include <qabstractrecorder.h>
#include <qrecorderwidget.h>
#include <qthreadinfodatanodewidget.h>
#include <qconnectioninfodatanodewidget.h>
#include <qabstractrobot.h>
#include <qrobotcommandwidget.h>

class QAbstractRobot;

class QRobotWindow : public QStackedWindow
{
    Q_OBJECT

public:
    explicit QRobotWindow(QAbstractRobot *robot, QWidget *parent = 0);

    QGPIODataNodeWidget *gpio();
    virtual QCommandWidget *command(QWidget *parent = 0);
    QAbstractRobot *robot();

    virtual void handleNewConnection(QSerialProtocol *connection);
    virtual void saveState(QString group);
    virtual void restoreState(QString group);

protected:
    QAbstractRobot *_robot;
    QGPIODataNodeWidget *_gpio = new QGPIODataNodeWidget(0);
    QRecorderWidget *_recorder = new QRecorderWidget(0);

    QMenu *_tools_menu;
    QMenu *_connection_menu;
    QMenu *_recorders_menu;

private slots:
    virtual void activate(bool checked);
    void statusText(QString text);

};

#endif // QROBOTWINDOW_H
