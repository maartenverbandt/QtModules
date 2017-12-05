#include "qgpiosignalgenerator.h"

QGPIOSignalGenerator::QGPIOSignalGenerator(QObject *parent) :
    QDataNode(parent)
{
    startTimer(20);
}

void QGPIOSignalGenerator::timerEvent(QTimerEvent *e)
{
    gpio_t gpio;
    gpio.gpio_float[0] = QTime::currentTime().second();
    gpio.gpio_int[0] = 60*sin(2*M_PI*2*QTime::currentTime().msecsSinceStartOfDay()*0.001);
    transmit(gpio);
}

void QGPIOSignalGenerator::receive(gpio_t gpio)
{
    qDebug() << gpio.gpio_float[0] << gpio.gpio_float[1];
    qDebug() << gpio.gpio_int[0] << gpio.gpio_int[1];
}
