#include "qrobotwindow.h"

#include <qshowthreadinginfoaction.h>
#include <qshowconnectioninfoaction.h>
#include <qshowparameterwidgetaction.h>
#include <qshowcommandwidgetaction.h>
#include <qgpiorecorder.h>

QRobotWindow::QRobotWindow(QAbstractRobot *robot, QWidget *parent) :
    QStackedWindow(parent), _robot(robot)
{
    // Set object name
    setObjectName(robot->type() + QString::number(robot->id()) + "_window");
    setWindowTitle(robot->objectName());
    //setWindowIcon(robot->icon());

    addView(_gpio->w());
    menuBar()->setNativeMenuBar(false); // Set menubar not native as it causes command tab not to be displayed

    // Setup threading
    _tools_menu = menuBar()->addMenu("Tools");
    _tools_menu->addAction(new QShowThreadingInfoAction(this, this));
    _tools_menu->addAction(new QShowParameterWidgetAction(this, this));

    // Setup connections
    _connection_menu = menuBar()->addMenu("Connections");

    // Setup recorders
    _recorders_menu = _recorder->menu();
    menuBar()->addMenu(_recorders_menu);
    statusBar()->addPermanentWidget(_recorder);
    QGPIORecorder *rec = new QGPIORecorder(_gpio->gpiow(), this);
    _recorder->add(rec);
    _recorder->setQuickRecord(rec);

    // Add command action
    menuBar()->addAction(new QShowCommandWidgetAction(this, this));

    // Add activate action
    QAction *activate = new QAction("activate",this);
    activate->setShortcut(Qt::CTRL + Qt::Key_X);
    activate->setCheckable(true);
    this->addAction(activate);
    QObject::connect(activate, &QAction::toggled, this, &QRobotWindow::activate);
    activate->setChecked(true);

    // String stitcher
    QObject::connect(_robot->getLog(), &QPrintLog::newline, this, &QRobotWindow::statusText);
}

void QRobotWindow::handleNewConnection(QSerialProtocol *connection)
{
    _gpio->connectTo(connection);
    _recorder->connectTo(connection);
    QMenu *m = _connection_menu->addMenu(connection->objectName());
    m->addAction(new QShowConnectionInfoAction(connection, this, this));
    m->addAction(connection->getActivateAction());
}

void QRobotWindow::activate(bool checked)
{
    setStackEnabled(checked);
    QListIterator<QSerialProtocol*> i(_robot->connections());
    while(i.hasNext())
        i.next()->getActivateAction()->setChecked(checked);
}

void QRobotWindow::statusText(QString text)
{
    statusBar()->showMessage(text, 5000);
}

QGPIODataNodeWidget *QRobotWindow::gpio()
{
    return _gpio;
}

QCommandWidget *QRobotWindow::command(QWidget *parent)
{
    return new QRobotCommandWidget(parent);
}

QAbstractRobot *QRobotWindow::robot()
{
    return _robot;
}

void QRobotWindow::saveState(QString group)
{
    _gpio->saveState(group);
}

void QRobotWindow::restoreState(QString group)
{
    _gpio->restoreState(group);
}
