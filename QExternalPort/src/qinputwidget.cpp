#include "qinputwidget.h"

QInputWidget::QInputWidget(QString name, QWidget *parent) : QWidget(parent)
{
    setObjectName(name);
    setLayout(new QVBoxLayout(this));
}

void QInputWidget::addPort(QDataPortInterface *port)
{
    layout()->addWidget(port->w());
    ports.append(port);
}

void QInputWidget::transmit()
{
    for(int i=0; i<ports.size(); i++){
        if(ports[i]->enabled())
            ports[i]->transmit_packet();
    }
}

void QInputWidget::reset()
{
    for(int i=0; i<ports.size(); i++){
        ports[i]->reset();
    }
}
