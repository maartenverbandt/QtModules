#include "mainwindow.h"
#include <QApplication>
#include <qtypecommandwidget.h>
#include <qtypeudpcommand.h>
#include <qcommandwidget.h>
#include <listener.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QCoreApplication::setOrganizationName("RobSoft");
    QCoreApplication::setApplicationName("UDPExample");
    MainWindow w;
    w.show();

    QTypeCommandWidget *udp = new QTypeCommandWidget("UDP",0);
    udp->add(new QGpioUdpCommand(udp));
    udp->add(new QPositionCmdUdpCommand(udp));

    QCommandWidget *d = new QCommandWidget(0);
    d->add(udp);
    d->show();

    Listener *l = new Listener(0);
    d->transmitTo(l);

    d->restoreState("udp_test");
    QObject::connect(&a,&QApplication::aboutToQuit,[=](){d->saveState("udp_test");});

    return a.exec();
}
