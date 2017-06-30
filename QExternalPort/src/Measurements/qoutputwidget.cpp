#include "qoutputwidget.h"

QOutputWidget::QOutputWidget(QString name, QWidget *parent) : QWidget(parent)
{
    setObjectName(name);
    setLayout(new QVBoxLayout(this));
}

void QOutputWidget::addPort(QMeasurementPortInterface *port)
{
    layout()->addWidget(port->getWidget());
    ports.append(port);
}

void QOutputWidget::setPackets(QList<QVariant> p)
{
    for(int i=0; i<ports.size(); i++){
        if(ports[i]->enabled())
            ports[i]->setPackets(p);
    }
}

void QOutputWidget::reset()
{
    for(int i=0; i<ports.size(); i++){
        ports[i]->reset();
    }
}

