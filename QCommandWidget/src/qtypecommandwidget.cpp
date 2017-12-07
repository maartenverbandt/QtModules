#include "qtypecommandwidget.h"

QTypeCommandWidget::QTypeCommandWidget(QString name, QWidget *parent) : QWidget(parent)
{
    setObjectName(name);
    _layout->addStretch(1.0);
    setLayout(_layout);
}

void QTypeCommandWidget::add(QDataPortInterface *port)
{
    _layout->insertWidget(_layout->count()-1, port->w());
    _ports.append(port);
}

void QTypeCommandWidget::transmitTo(QDataNode *other)
{
    QListIterator<QDataPortInterface *> i(_ports);
    while(i.hasNext())
        i.next()->transmitTo(other);
}

void QTypeCommandWidget::transmit()
{
    for(int i=0; i<_ports.size(); i++){
        if(_ports[i]->enabled())
            _ports[i]->transmit_packet();
    }
}

void QTypeCommandWidget::reset()
{
    for(int i=0; i<_ports.size(); i++){
        _ports[i]->reset();
    }
}
