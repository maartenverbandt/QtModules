#include "qheartbeatchecker.h"

QHeartbeatChecker::QHeartbeatChecker(QDataNode *datanode, QWidget *parent) :
    QDataNodeWidget(parent)
{
    _label = new QLabel("DEAD", parent);
    _label->setMinimumSize(200,40);
    _label->setAlignment(Qt::AlignCenter);
    connectTo(datanode);
}

QWidget *QHeartbeatChecker::w()
{
    return _label;
}

void QHeartbeatChecker::receive(heartbeat_t heartbeat)
{
    _label->setText("ALIVE (" + QString::number(heartbeat.time) + ")");
}

