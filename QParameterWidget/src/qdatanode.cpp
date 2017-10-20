#include "qdatanode.h"

QDataNode::QDataNode(QObject *parent) : QObject(parent)
{

}

void QDataNode::transmitTo(QDataNode *other)
{
    QObject::connect(this, SIGNAL(transmit(heartbeat_t)), other, SLOT(receive(heartbeat_t)));
    QObject::connect(this, SIGNAL(transmit(event_t)), other, SLOT(receive(event_t)));
    QObject::connect(this, SIGNAL(transmit(param_int_t)), other, SLOT(receive(param_int_t)));
    QObject::connect(this, SIGNAL(transmit(param_float_t)), other, SLOT(receive(param_float_t)));
    QObject::connect(this, SIGNAL(transmit(param_string_t)), other, SLOT(receive(param_string_t)));
}

void QDataNode::receiveFrom(QDataNode *other)
{
    other->transmitTo(this);
}

void QDataNode::connect(QDataNode *n1, QDataNode *n2)
{
    n1->transmitTo(n2);
    n2->transmitTo(n1);
}
