#include <QtGui>
#include <QApplication>

#include <qrobotoverview.h>
#include <qballbot.h>
#include <qcar.h>
#include <qtiltingtable.h>
#include <qunknownrobot.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    
    QRobotOverview *r = new QRobotOverview(0);
    r->show();

    r->addRobot(new QBallbot(0,0));
    r->addRobot(new QCar(10,0));
    r->addRobot(new QTiltingTable(20,0));
    r->addRobot(new QUnknownRobot(30,0));

    return a.exec();
}
