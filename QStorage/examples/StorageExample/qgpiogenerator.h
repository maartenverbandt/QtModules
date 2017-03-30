#ifndef QGPIOGENERATOR_H
#define QGPIOGENERATOR_H

#include <QObject>
#include <QTime>
#include <QVariant>
#include <mavlink.h>

class QGpioGenerator : public QObject
{
    Q_OBJECT

public:
    QGpioGenerator(QObject *parent = 0);

protected:
    virtual void timerEvent(QTimerEvent *e);

signals:
    void sendPacket(QList<QVariant> list);

};

#endif // QGPIOGENERATOR_H
