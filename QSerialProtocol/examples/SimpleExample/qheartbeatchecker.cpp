#include "qheartbeatchecker.h"

QHeartbeatChecker::QHeartbeatChecker(QDataNode *datanode, QWidget *parent) :
    QDataNodeWidget(parent)
{
    _label = new QLabel("DEAD", parent);
    _label->setMinimumSize(200,40);
    _label->setAlignment(Qt::AlignCenter);
    _w = _label;
    connectTo(datanode);
}

void QHeartbeatChecker::receive(heartbeat_t heartbeat)
{
    _label->setText("ALIVE (" + QString::number(heartbeat.time) + ")");
}

