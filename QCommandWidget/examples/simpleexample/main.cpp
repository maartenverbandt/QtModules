#include "mainwindow.h"
#include <QApplication>
#include <qtypecommandwidget.h>
#include <qgpiocsvcommand.h>
#include <qpositioncmdcsvcommand.h>
#include <qtypeudpcommand.h>
#include <qgamepadcommandwidget.h>
#include <qvelocitygamepadcommand.h>
#include <qcommandwidget.h>
#include <listener.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    QTypeCommandWidget *csv = new QTypeCommandWidget("CSV",0);
    csv->add(new QGpioCsvCommand(csv));
    csv->add(new QPositionCmdCsvCommand(csv));

    QTypeCommandWidget *udp = new QTypeCommandWidget("UDP",0);
    udp->add(new QGpioUdpCommand(udp));
    udp->add(new QPositionCmdUdpCommand(udp));

    QGamepadCommandWidget *gamepad = new QGamepadCommandWidget("Gamepad");
    gamepad->add(new QVelocityGamepadCommand(gamepad));

    QCommandWidget *d = new QCommandWidget(0);
    d->add(csv);
    d->add(udp);
    d->add(gamepad);
    d->show();

    Listener *l = new Listener(0);
    d->transmitTo(l);

    return a.exec();
}
