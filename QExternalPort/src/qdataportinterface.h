#ifndef QDATAPORTINTERFACE_H
#define QDATAPORTINTERFACE_H

#include <qdatanodewidget.h>

class QDataPortInterface : public QDataNodeWidget
{
    Q_OBJECT
public:
    QDataPortInterface(QWidget *parent = 0) : QDataNodeWidget(parent){}

    virtual QWidget *w() = 0;
    virtual void transmit_packet() = 0;
    virtual bool enabled() = 0;
    virtual void reset() = 0;

};

#endif // QDATAPORTINTERFACE_H
