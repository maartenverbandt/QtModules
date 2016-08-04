#include "ballbotconfigdialog.h"

BallbotConfigDialog::BallbotConfigDialog(QWidget *parent) : QRobotConfigDialog(parent)
{
    /*_config.microos_runtime = 0;
    _config.ballbot_runtime = 0;
    _config.ballbot_dropcount = 0;
    _config.roll_offset = 0.0f;
    _config.pitch_offset = 0.0f;
    _config.default_attitude_controller = 1;
    _config.default_yaw_controller = 1;
    _config.default_position_controller = 1;

    load(_config);*/

    addGroup("Stats");
    addParameter("microOS runtime",&_config.microos_runtime,"Stats");
    addParameter("ballbot runtime",&_config.ballbot_runtime,"Stats");
    addParameter("ballbot dropcount",&_config.ballbot_dropcount,"Stats");
    addGroup("IMU");
    addParameter("roll offset",&_config.roll_offset,"IMU");
    addParameter("pitch offset",&_config.pitch_offset,"IMU");
    addGroup("Controllers");
    addParameter("attitude controller",&_config.default_attitude_controller,"Controllers");
    addParameter("yaw controller",&_config.default_yaw_controller,"Controllers");
    addParameter("position controller",&_config.default_position_controller,"Controllers");
}

BallbotConfigDialog::~BallbotConfigDialog()
{

}

QByteArray BallbotConfigDialog::getByteArray()
{
    QByteArray data((char*)(&_config), sizeof(_config));
    qDebug() << *((int*)data.data());

    return data;
}

void BallbotConfigDialog::fromByteArray(const QByteArray &data)
{
    _config = *reinterpret_cast<const ballbot_config_t*>(data.data());
}

/*void BallbotConfigDialog::load(ballbot_config_t config)
{
    addGroup("Stats");
    addParameter("microOS runtime",&_config.microos_runtime,"Stats");
    addParameter("ballbot runtime",&_config.ballbot_runtime,"Stats");
    addParameter("ballbot dropcount",&_config.ballbot_dropcount,"Stats");
    addGroup("IMU");
    addParameter("roll offset",&_config.roll_offset,"IMU");
    addParameter("pitch offset",&_config.pitch_offset,"IMU");
    addGroup("Controllers");
    addParameter("attitude controller",&_config.default_attitude_controller,"Controllers");
    addParameter("yaw controller",&_config.default_yaw_controller,"Controllers");
    addParameter("position controller",&_config.default_position_controller,"Controllers");
}*/

