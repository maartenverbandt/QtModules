#ifndef QGPIOPORTINTERFACE_H
#define QGPIOPORTINTERFACE_H

#include <qdataportinterface.h>
#include <mavlink/robot_messages/mavlink.h>

class QGPIOPortInterface : public QDataPortInterface
{
public:
    virtual mavlink_gpio_t getGpioPacket() = 0;

};

Q_DECLARE_METATYPE(mavlink_gpio_t)

#endif // QGPIOPORTINTERFACE_H
