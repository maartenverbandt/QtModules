#ifndef QSIMPLEROBOTCONFIG_H
#define QSIMPLEROBOTCONFIG_H

#include <qrobotconfigdialog.h>

typedef struct __attribute__((__packed__)) robot_config_t{
    // robot statistics
    quint32 microos_runtime;
    quint32 robot_runtime;
    // robot parameters
    quint8  robot_id;
    // control setpoints
    float some_parameter;
} robot_config_t;

class QSimpleRobotConfig : public QRobotConfigDialog
{
public:
    QSimpleRobotConfig();
    ~QSimpleRobotConfig();

    QByteArray getByteArray();
    void fromByteArray(const QByteArray &data);

private:
    robot_config_t _config;
};

#endif // QSIMPLEROBOTCONFIG_H
