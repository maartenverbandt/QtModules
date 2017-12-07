#include "mainwindow.h"
#include <QApplication>
#include <qtypecommandwidget.h>
#include <qgpiocsvcommand.h>
#include <qpositioncmdcsvcommand.h>
#include <qtypeudpcommand.h>
#include <qcommandgamepadwidget.h>
#include <qvelocitygamepadcommand.h>
#include <qcommandwidget.h>
#include <listener.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    QCommandTypeWidget *csv = new QCommandTypeWidget("CSV",0);
    csv->add(new QGpioCsvReader(csv));
    csv->add(new QPositionCmdCsvReader(csv));

    QCommandTypeWidget *udp = new QCommandTypeWidget("UDP",0);
    udp->add(new QGpioUdpReader(udp));
    udp->add(new QPositionCmdUdpReader(udp));

    //QCommandGamepadWidget *gamepad = new QCommandGamepadWidget("Gamepad");
    //gamepad->add(new QVelocityGamepadCommand(gamepad));

    QCommandWidget *d = new QCommandWidget(0);
    d->add(csv);
    d->add(udp);
    //d->add(gamepad);
    d->show();

    Listener *l = new Listener(0);
    d->transmitTo(l);

    return a.exec();
}
