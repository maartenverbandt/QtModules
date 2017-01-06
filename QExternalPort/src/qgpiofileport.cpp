#include "qgpiofileport.h"

QGPIOFilePort::QGPIOFilePort(QObject *parent) :
    QObject(parent),
    _csv_reader(new QCsvReaderWidget(0))
{

}

mavlink_gpio_t QGPIOFilePort::getGpioPacket()
{
    int k = 0;
    mavlink_gpio_t gpio;

    QList<double> values = _csv_reader->readLine();
    while(values.length() < 12)
        values.append(0.0);

    QListIterator<double> i(values);
    for(k=0;k<8;k++){
        gpio.gpio_float[k] = i.next();
    }
    for(k=0;k<4;k++){
        gpio.gpio_int[k] = i.next();
    }

    return gpio;
}

QVariant QGPIOFilePort::getPacket()
{
    QVariant gpio;
    gpio.setValue(getGpioPacket());
    return gpio;
}

QWidget *QGPIOFilePort::getWidget()
{
    return _csv_reader;
}


