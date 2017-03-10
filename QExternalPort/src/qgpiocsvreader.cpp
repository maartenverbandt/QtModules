#include "qgpiocsvreader.h"

QGpioCsvReader::QGpioCsvReader(QWidget *parent) :
    _csv_reader(new QCsvReaderWidget("gpio", parent))
{

}

mavlink_gpio_t QGpioCsvReader::getGpioPacket()
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

QVariant QGpioCsvReader::getPacket()
{
    QVariant gpio;
    gpio.setValue(getGpioPacket());
    return gpio;
}

QWidget *QGpioCsvReader::getWidget()
{
    return _csv_reader;
}

bool QGpioCsvReader::enabled()
{
    return _csv_reader->enabled();
}

void QGpioCsvReader::reset()
{
    _csv_reader->getCsvReader()->reset();
}


