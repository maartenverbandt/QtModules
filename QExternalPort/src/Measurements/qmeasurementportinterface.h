#ifndef QMEASUREMENTPORTINTERFACE_H
#define QMEASUREMENTPORTINTERFACE_H

#include <qvariant.h>
#include <qwidget.h>

class QMeasurementPortInterface
{
public:
    virtual void setPacket(QVariant packet) = 0;
    virtual void setPackets(QList<QVariant> l) {
        QListIterator<QVariant> i(l);
        while (i.hasNext()) {
            setPacket(i.next());
        }
    }
    virtual QWidget* getWidget() = 0;

    virtual bool enabled() = 0;
    virtual void reset() = 0;

};

#endif // QMEASUREMENTPORTINTERFACE_H
