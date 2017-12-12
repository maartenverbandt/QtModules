#ifndef QBALANCINGWINDOW_H
#define QBALANCINGWINDOW_H

#include <qrobotwindow.h>
#include <qbalancingdatanodewidget.h>
#include <qexcitationdock.h>

class QBalancingWindow : public QRobotWindow
{
    Q_OBJECT

public:
    explicit QBalancingWindow(QAbstractRobot *robot, QWidget *parent = 0);

    QBalancingDataNodeWidget *balance();

    virtual void handleNewConnection(QSerialProtocol *connection);

private:
    QBalancingDataNodeWidget *_balance;

};

#endif // QBALANCINGWINDOW_H
