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

void QDataNode::connectTo(QDataNode *other)
{
    transmitTo(other);
    receiveFrom(other);
}
