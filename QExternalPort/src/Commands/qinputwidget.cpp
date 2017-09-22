#include "qinputwidget.h"

QInputWidget::QInputWidget(QString name, QWidget *parent) : QWidget(parent)
{
    setObjectName(name);
    setLayout(new QVBoxLayout(this));
}

void QInputWidget::addPort(QDataPortInterface *port)
{
    layout()->addWidget(port->getWidget());
    ports.append(port);
}

QList<QVariant> QInputWidget::read()
{
    QList<QVariant> p;

    for(int i=0; i<ports.size(); i++){
        if(ports[i]->enabled())
            p.append(ports[i]->getPacket());
    }

    return p;
}

void QInputWidget::reset()
{
    for(int i=0; i<ports.size(); i++){
        ports[i]->reset();
    }
}

void QInputWidget::saveState(QString group)
{
    QListIterator<QDataPortInterface*> i(ports);
    while(i.hasNext()){
        i.next()->saveState(group + "/" + objectName());
    }
}

void QInputWidget::restoreState(QString group)
{
    QListIterator<QDataPortInterface*> i(ports);
    while(i.hasNext()){
        i.next()->restoreState(group + "/" + objectName());
    }
}
