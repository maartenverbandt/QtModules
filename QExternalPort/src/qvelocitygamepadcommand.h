#ifndef QVELOCITYGAMEPADCOMMAND_H
#define QVELOCITYGAMEPADCOMMAND_H

#include <qgamepadcommand.h>
#include <mavlink.h>

class QVelocityGamepadCommand : public QGamepadCommand
{
public:
    QVelocityGamepadCommand(QObject *parent = 0);

    mavlink_velocity_cmd_t getVelocityCmdPacket();
    virtual QVariant getPacket();

};

#endif // QVELOCITYGAMEPADCOMMAND_H
