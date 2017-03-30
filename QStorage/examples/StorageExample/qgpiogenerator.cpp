#include "qgpiogenerator.h"

QGpioGenerator::QGpioGenerator(QObject *parent) : QObject(parent)
{
    startTimer(20);
}

void QGpioGenerator::timerEvent(QTimerEvent *e)
{
    QList<QVariant> list;
    mavlink_gpio_t gpio;
    gpio.gpio_float[0] = QTime::currentTime().msec();
    gpio.gpio_float[1] = QTime::currentTime().second();
    gpio.gpio_int[0] = QTime::currentTime().msec();
    gpio.gpio_int[1] = QTime::currentTime().second();

    QVariant packet;
    packet.setValue<mavlink_gpio_t>(gpio);
    list.append(packet);
    emit sendPacket(list);
}
