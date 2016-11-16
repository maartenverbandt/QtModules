#include "qcontrollerdevicereader.h"

QControllerDeviceReader::QControllerDeviceReader(QObject *parent) : QObject(parent)
{

}

void QControllerDeviceReader::axisChanged(int id, double value)
{
    qDebug() << "Axis" << id << "changed:" << value;
}

void QControllerDeviceReader::buttonChanged(int id, bool value)
{
    qDebug() << "Button" << id << "changed:" << value;
}

void QControllerDeviceReader::switchNextRobot()
{
    qDebug() << "Switch to next robot.";
}

void QControllerDeviceReader::switchPrevRobot()
{
    qDebug() << "Switch to previous robot.";
}

void QControllerDeviceReader::toggleRecorder()
{
    qDebug() << "Recorder toggled.";
}

void QControllerDeviceReader::moveRobot(QControllerDeviceInterface::robot_move_cmd_t cmd)
{
    //qDebug() << "New movement requested:" << QVector3D(cmd.x,cmd.y,cmd.z);
}
