#include "qbalancingwindow.h"

QBalancingWindow::QBalancingWindow(QAbstractRobot *robot, QWidget *parent) :
    QRobotWindow(robot, parent),
    _balance(new QBalancingDataNodeWidget(this))
{
    addView(_balance->w());

    _tools_menu->addAction(new QShowExcitationWindowAction(this, this));
}

QBalancingDataNodeWidget *QBalancingWindow::balance()
{
    return _balance;
}

void QBalancingWindow::handleNewConnection(QSerialProtocol *connection)
{
    QRobotWindow::handleNewConnection(connection);
    connection->connectTo(_balance);
}
