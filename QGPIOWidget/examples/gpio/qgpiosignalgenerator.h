#ifndef QGPIOSIGNALGENERATOR_H
#define QGPIOSIGNALGENERATOR_H

#include <QTime>
#include <QDebug>
#include <qdatanode.h>

class QGPIOSignalGenerator : public QDataNode
{
    Q_OBJECT

public:
    explicit QGPIOSignalGenerator(QObject *parent = 0);

protected:
    virtual void timerEvent(QTimerEvent *e);

public slots:
    virtual void receive(gpio_t);

};

#endif // QGPIOSIGNALGENERATOR_H
