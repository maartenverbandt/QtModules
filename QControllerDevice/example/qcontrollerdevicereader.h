#ifndef QCONTROLLERDEVICEREADER_H
#define QCONTROLLERDEVICEREADER_H

#include <QObject>
#include <QDebug>
#include <QVector3D>
#include <qcontrollerdeviceinterface.h>

class QControllerDeviceReader : public QObject
{
    Q_OBJECT
public:
    explicit QControllerDeviceReader(QObject *parent = 0);

public slots:
    void axisChanged(int id, double value);
    void buttonChanged(int id, bool value);

    void switchNextRobot();
    void switchPrevRobot();
    void toggleRecorder();
    void moveRobot(QControllerDeviceInterface::robot_move_cmd_t cmd);

};

#endif // QCONTROLLERDEVICEREADER_H
