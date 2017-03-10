#ifndef MAVLINK_CONNECTION_INCLUDE_H
#define MAVLINK_CONNECTION_INCLUDE_H

//#include "/home/maarten/projects/mavlink/build/include/v1.0/microos_messages/mavlink.h"
//#include "/home/maarten/projects/mavlink/build/include/v1.0/ballbot_messagesavr/mavlink.h"
#include "mavlink/robot_messages/mavlink.h"

Q_DECLARE_METATYPE(mavlink_gpio_t)
Q_DECLARE_METATYPE(mavlink_thread_info_t)
Q_DECLARE_METATYPE(mavlink_event_t)
Q_DECLARE_METATYPE(mavlink_partition_t)
Q_DECLARE_METATYPE(mavlink_attitude_cmd_t)
Q_DECLARE_METATYPE(mavlink_velocity_cmd_t)
Q_DECLARE_METATYPE(mavlink_position_cmd_t)
Q_DECLARE_METATYPE(mavlink_signal_sweptsine_t)
Q_DECLARE_METATYPE(mavlink_signal_multisine_t)
Q_DECLARE_METATYPE(mavlink_signal_steppedsine_t)

#endif //MAVLINK_CONNECTION_INCLUDE_H
