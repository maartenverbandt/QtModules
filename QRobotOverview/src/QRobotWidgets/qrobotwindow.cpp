#include "qrobotwindow.h"

#include <qshowthreadinginfoaction.h>
#include <qshowconnectioninfoaction.h>
#include <qgpiorecorder.h>

QRobotWindow::QRobotWindow(QAbstractRobot *robot, QWidget *parent) :
    QStackedWindow(parent), _robot(robot)
{
    // Set object name
    setObjectName(robot->type() + QString::number(robot->id()) + "_window");

    addView(_gpio->w());
    menuBar()->setNativeMenuBar(false); // Set menubar not native as it causes command tab not to be displayed

    // Setup threading
    _tools_menu = menuBar()->addMenu("Tools");
    _tools_menu->addAction(new QShowThreadingInfoAction(this, this));

    // Setup connections
    _connection_menu = menuBar()->addMenu("Connections");

    // Setup recorders
    _recorders_menu = _recorder->menu();
    menuBar()->addMenu(_recorders_menu);
    statusBar()->addPermanentWidget(_recorder);
    QGPIORecorder *rec = new QGPIORecorder(_gpio->gpiow(), this);
    _recorder->add(rec);
    _recorder->setQuickRecord(rec);

    // Add activate action
    QAction *activate = new QAction("activate",this);
    activate->setShortcut(Qt::CTRL + Qt::Key_X);
    activate->setCheckable(true);
    this->addAction(activate);
    QObject::connect(activate, &QAction::toggled, this, &QRobotWindow::activate);
    activate->setChecked(true);
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

QGPIODataNodeWidget *QRobotWindow::gpio()
{
    return _gpio;
}

QAbstractRobot *QRobotWindow::robot()
{
    return _robot;
}

/*void QRobotWindow::saveState(QString group)
{
    _gpio->saveState(group);
}

void QRobotWindow::restoreState(QString group)
{
    _gpio->restoreState(group);
}
*/