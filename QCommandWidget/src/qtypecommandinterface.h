#ifndef QTYPECOMMANDINTERFACE_H
#define QTYPECOMMANDINTERFACE_H

#include <qdatanodewidget.h>

class QTypeCommandInterface : public QDataNodeWidget
{
    Q_OBJECT
public:
    QDataPortInterface(QWidget *parent = 0) : QDataNodeWidget(parent){}

    virtual QWidget *w() = 0;
    virtual void transmit_packet() = 0;
    virtual bool enabled() = 0;
    virtual void reset() = 0;

};

#endif // QTYPECOMMANDINTERFACE_H
