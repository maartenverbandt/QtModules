#ifndef QROBOTWINDOW_H
#define QROBOTWINDOW_H

#include <qabstractrobot.h>
class QAbstractRobot;

#include <QStatusBar>
#include <QMenuBar>
#include <QLabel>
#include <qstackedwindow.h>
#include <qgpiodatanodewidget.h>
#include <qabstractrecorder.h>
#include <qrecorderwidget.h>
#include <qthreadinfodatanodewidget.h>
#include <qconnectioninfodatanodewidget.h>
#include <qrobotcommandwidget.h>


class QRobotWindow : public QStackedWindow
{
    Q_OBJECT

public:
    explicit QRobotWindow(QAbstractRobot *robot, QWidget *parent = 0);

    QGPIODataNodeWidget *gpio();
    virtual QCommandWidget *command(QWidget *parent = 0);
    QAbstractRobot *robot();
    QString group();

    virtual void handleNewConnection(QSerialProtocol *connection);

protected:
    QAbstractRobot *_robot;
    QGPIODataNodeWidget *_gpio = new QGPIODataNodeWidget(0);
    QRecorderWidget *_recorder = new QRecorderWidget(0);

    QMenu *_tools_menu;
    QMenu *_connection_menu;
    QMenu *_recorders_menu;

    virtual void showEvent(QShowEvent *);
    virtual void closeEvent(QCloseEvent *);

private slots:
    virtual void activate(bool checked);
    void statusText(QString text);

signals:
    void closing();

};

#endif // QROBOTWINDOW_H
