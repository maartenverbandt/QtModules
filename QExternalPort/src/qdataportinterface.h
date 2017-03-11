#ifndef QDATAPORTINTERFACE_H
#define QDATAPORTINTERFACE_H

#include <qvariant.h>
#include <qwidget.h>

class QDataPortInterface
{
public:
    virtual QVariant getPacket() = 0;
    virtual QWidget* getWidget() = 0;

    virtual bool enabled() = 0;
    virtual void reset() = 0;

};

#endif // QDATAPORTINTERFACE_H
