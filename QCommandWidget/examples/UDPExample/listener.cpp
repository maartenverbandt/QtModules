#include "listener.h"

Listener::Listener(QObject *parent) : QDataNode(parent)
{

}

void Listener::receive(gpio_t gpio)
{
    qDebug() << "Type: mavlink_gpio_t";
    qDebug() << gpio.gpio_float[0] << gpio.time;
}

void Listener::receive(velocity_cmd_t cmd)
{
    qDebug() << "Type: velocity_cmd_t";
    qDebug() << cmd.vx << cmd.vy;
}

void Listener::receive(position_cmd_t cmd)
{
    qDebug() << "Type: position_cmd_t";
    qDebug() << cmd.x << cmd.y;
}
