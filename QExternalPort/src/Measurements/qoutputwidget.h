#ifndef QOUTPUTPORT_H
#define QOUTPUTPORT_H

#include <QWidget>
#include <QLayout>
#include <QDebug>
#include <qmeasurementportinterface.h>

class QOutputWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QOutputWidget(QString name, QWidget *parent = 0);

    void addPort(QMeasurementPortInterface *port);
    virtual void setPackets(QList<QVariant> p);
    void reset();

protected:
    QList<QMeasurementPortInterface*> ports;

};

#endif // QOUTPUTPORT_H
