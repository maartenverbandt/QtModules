#include "mainwindow.h"
#include <QApplication>
#include <qinputwidget.h>
#include <qgpiocsvreader.h>
#include <qpositioncmdcsvreader.h>
#include <qtudpreader.h>
#include <qgamepadinputwidget.h>
#include <qvelocitygamepadcommand.h>
#include <mavlink.h>
#include <qexternalportdialog.h>
#include <listener.h>

#include <qoutputwidget.h>
#include <qtudpwriter.h>
#include <qmeasurementportdialog.h>
#include <talker.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    QInputWidget *csv = new QInputWidget("CSV",0);
    csv->addPort(new QGpioCsvReader(csv));
    csv->addPort(new QPositionCmdCsvReader(csv));

    QInputWidget *udp = new QInputWidget("UDP",0);
    udp->addPort(new QGpioUdpReader(udp));
    udp->addPort(new QPositionCmdUdpReader(udp));

    QGamepadInputWidget *gamepad = new QGamepadInputWidget("Gamepad");
    gamepad->addPort(new QVelocityGamepadCommand(gamepad));

    QExternalPortDialog *d = new QExternalPortDialog("Command port");
    d->addInputWidget(csv);
    d->addInputWidget(udp);
    d->addInputWidget(gamepad);
    d->show();

    Listener l;
    QObject::connect(d,&QExternalPortDialog::commands,&l,&Listener::message_received);

    QOutputWidget *udp2 = new QOutputWidget("UDP",0);
    udp2->addPort(new QGpioUdpWriter(udp2));
    udp2->addPort(new QAttitudeUdpWriter(udp2));
    QMeasurementPortDialog *d2 = new QMeasurementPortDialog("Measurement port");
    d2->addOutputWidget(udp2);
    d2->show();

    Talker t;
    QObject::connect(&t,&Talker::message_sent,d2,&QMeasurementPortDialog::measurements);

    return a.exec();
}
