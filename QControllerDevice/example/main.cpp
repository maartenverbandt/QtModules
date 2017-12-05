#include <QCoreApplication>
#include <qcontrollerdeviceinterface.h>
#include <qtrustmaster.h>
#include <qcontrollerdevicereader.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QTrustMaster* d = new QTrustMaster();
    QControllerDeviceReader* r = new QControllerDeviceReader();
    QObject::connect(d,SIGNAL(axisStateChanged(int,double)),r,SLOT(axisChanged(int,double)));
    QObject::connect(d,SIGNAL(buttonStateChanged(int,bool)),r,SLOT(buttonChanged(int,bool)));
    QObject::connect(d,SIGNAL(switchNextRobot()),r,SLOT(switchNextRobot()));
    QObject::connect(d,SIGNAL(switchPrevRobot()),r,SLOT(switchPrevRobot()));
    QObject::connect(d,SIGNAL(toggleRecorder()),r,SLOT(toggleRecorder()));
    QObject::connect(d,SIGNAL(moveCmdChanged(QControllerDeviceInterface::robot_move_cmd_t)),r,SLOT(moveRobot(QControllerDeviceInterface::robot_move_cmd_t)));

    d->start();

    return a.exec();
}
