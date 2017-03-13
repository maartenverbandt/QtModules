#include "listener.h"

Listener::Listener(QObject *parent) : QObject(parent)
{

}

void Listener::message_received(QList<QVariant> l)
{
    QListIterator<QVariant> i(l);
    int type;
    while(i.hasNext()){
        type = i.peekNext().userType();
        if(type == qMetaTypeId<mavlink_gpio_t>()) {
            qDebug() << "Type: mavlink_gpio_t";
            mavlink_gpio_t gpio = i.next().value<mavlink_gpio_t>();
            qDebug() << gpio.gpio_float[0] << gpio.time;
        } else if(type == qMetaTypeId<mavlink_velocity_cmd_t>()) {
            qDebug() << "Type: mavlink_velocity_cmd_t";
            mavlink_velocity_cmd_t cmd = i.next().value<mavlink_velocity_cmd_t>();
            qDebug() << cmd.vx << cmd.vy;
        } else if(type == qMetaTypeId<mavlink_position_cmd_t>()) {
            qDebug() << "Type: mavlink_position_cmd_t";
            mavlink_position_cmd_t cmd = i.next().value<mavlink_position_cmd_t>();
            qDebug() << cmd.x << cmd.y;
        } else {
            qDebug() << "Type unknown";
        }
    }
}
