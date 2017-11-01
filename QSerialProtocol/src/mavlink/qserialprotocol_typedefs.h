#ifndef QSERIALPROTOCOL_TYPEDEFS_H
#define QSERIALPROTOCOL_TYPEDEFS_H

#include "mavlink/robot_messages/mavlink.h"
#include <QMetaType>

typedef mavlink_heartbeat_t heartbeat_t;
typedef mavlink_gpio_t gpio_t;
typedef mavlink_thread_info_t thread_info_t;
typedef mavlink_event_t event_t;
typedef mavlink_partition_t partition_t;
typedef mavlink_param_int_t param_int_t;
typedef mavlink_param_float_t param_float_t;
typedef mavlink_param_string_t param_string_t;
typedef mavlink_param_data_t param_data_t;
typedef mavlink_attitude_cmd_t attitude_cmd_t;
typedef mavlink_velocity_cmd_t velocity_cmd_t;
typedef mavlink_position_cmd_t position_cmd_t;
typedef mavlink_signal_sweptsine_t signal_sweptsine_t;
typedef mavlink_signal_multisine_t signal_multisine_t;
typedef mavlink_signal_steppedsine_t signal_steppedsine_t;

Q_DECLARE_METATYPE(gpio_t)
Q_DECLARE_METATYPE(thread_info_t)
Q_DECLARE_METATYPE(event_t)
Q_DECLARE_METATYPE(partition_t)
Q_DECLARE_METATYPE(param_int_t)
Q_DECLARE_METATYPE(param_float_t)
Q_DECLARE_METATYPE(param_string_t)
Q_DECLARE_METATYPE(param_data_t)
Q_DECLARE_METATYPE(mavlink_attitude_cmd_t)
Q_DECLARE_METATYPE(mavlink_velocity_cmd_t)
Q_DECLARE_METATYPE(mavlink_position_cmd_t)
Q_DECLARE_METATYPE(mavlink_signal_sweptsine_t)
Q_DECLARE_METATYPE(mavlink_signal_multisine_t)
Q_DECLARE_METATYPE(mavlink_signal_steppedsine_t)

enum event_id_t {
    PARAMETERS_REQUEST_SEND = 100,
    PARAMETERS_REQUEST_ST0RE = 101
};

enum robot_type_t {
    BALLBOT = 10,
    SEGBOT = 11,
    TILTINGTABLE = 12,
    CAR = 20
};

#endif // QSERIALPROTOCOL_TYPEDEFS_H
