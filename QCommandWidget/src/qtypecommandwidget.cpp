#include "qtypecommandwidget.h"

QCommandTypeWidget::QCommandTypeWidget(QString name, QWidget *parent) : QWidget(parent)
{
    setObjectName(name);
    setLayout(new QVBoxLayout(this));
}

void QCommandTypeWidget::add(QDataPortInterface *port)
{
    layout()->addWidget(port->w());
    _ports.append(port);
}

void QCommandTypeWidget::transmitTo(QDataNode *other)
{
    QListIterator<QDataPortInterface *> i(_ports);
    while(i.hasNext())
        i.next()->transmitTo(other);
}

void QCommandTypeWidget::transmit()
{
    for(int i=0; i<_ports.size(); i++){
        if(_ports[i]->enabled())
            _ports[i]->transmit_packet();
    }
}

void QCommandTypeWidget::reset()
{
    for(int i=0; i<_ports.size(); i++){
        _ports[i]->reset();
    }
}
