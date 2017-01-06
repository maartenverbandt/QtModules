#ifndef QPOSITIONCMDPORTINTERFACE_H
#define QPOSITIONCMDPORTINTERFACE_H

#include <qdataportinterface.h>
#include <mavlink/robot_messages/mavlink.h>

class QPositionCmdPortInterface: public QDataPortInterface
{
public:
    virtual mavlink_position_cmd_t getPositionCmdPacket() = 0;

};

Q_DECLARE_METATYPE(mavlink_position_cmd_t)

#endif // QPOSITIONCMDPORTINTERFACE_H
