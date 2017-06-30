#include "talker.h"

Talker::Talker(QObject *parent) : QObject(parent)
{
    startTimer(1000);
}

void Talker::timerEvent(QTimerEvent *e)
{
    QList<QVariant> packetlist;
    mavlink_gpio_t gpio;
    gpio.gpio_int[0] = QTime::currentTime().second();
    qDebug() << gpio.gpio_int[0];
    mavlink_position_cmd_t cmd;
    cmd.x = QTime::currentTime().second();

    packetlist.append(QVariant::fromValue(gpio));
    packetlist.append(QVariant::fromValue(cmd));

    message_sent(packetlist);
}
