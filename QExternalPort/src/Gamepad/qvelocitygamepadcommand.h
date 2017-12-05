#ifndef QVELOCITYGAMEPADCOMMAND_H
#define QVELOCITYGAMEPADCOMMAND_H

#include <qgamepadcommand.h>

class QVelocityGamepadCommand : public QGamepadCommand
{
public:
    QVelocityGamepadCommand(QWidget *parent = 0);
    virtual void transmit_packet();

};

#endif // QVELOCITYGAMEPADCOMMAND_H
