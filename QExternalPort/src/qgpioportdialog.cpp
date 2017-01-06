#include "qgpioportdialog.h"

QGPIOPortDialog::QGPIOPortDialog(QWidget *parent = 0) :
    QExternalPortDialog("gpio",parent),
    _file_port(new QGPIOFilePort(this))
{
    addPort(_file_port,"file");
}

mavlink_gpio_t QGPIOPortDialog::getGpioPacket()
{
    QVariant gpio = getPacket();
    return gpio.value<mavlink_gpio_t>();
}
