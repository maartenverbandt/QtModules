#include "qsimplerobotconfig.h"

QSimpleRobotConfig::QSimpleRobotConfig()
{
    addGroup("Stats");
    addParameter("microOS runtime",&_config.microos_runtime,"Stats");
    addParameter("ballbot runtime",&_config.robot_runtime,"Stats");
    addGroup("Parameters");
    addParameter("id",&_config.robot_id,"Parameters");
    addParameter("some_parameter",&_config.some_parameter,"Parameters");
}

QSimpleRobotConfig::~QSimpleRobotConfig(){}

QByteArray QSimpleRobotConfig::getByteArray()
{
    QByteArray data((char*)(&_config), sizeof(_config));
    qDebug() << *((int*)data.data());

    return data;
}

void QSimpleRobotConfig::fromByteArray(const QByteArray &data)
{
    _config = *reinterpret_cast<const robot_config_t*>(data.data());
}

