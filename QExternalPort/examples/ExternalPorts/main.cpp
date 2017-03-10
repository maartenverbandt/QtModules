#include "mainwindow.h"
#include <QApplication>
#include <qinputwidget.h>
#include <qgpiocsvreader.h>
#include <qpositioncmdcsvreader.h>
#include <qtudpreader.h>
#include <mavlink.h>
#include <qexternalportdialog.h>
#include <listener.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    QInputWidget *csv = new QInputWidget(0);
    QGpioCsvReader *gpio = new QGpioCsvReader(csv);
    QPositionCmdCsvReader *pcmd = new QPositionCmdCsvReader(csv);

    csv->addPort(gpio);
    csv->addPort(pcmd);
    //csv->show();

    QInputWidget *udp = new QInputWidget(0);
    QDataPortInterface *gpio_udp = new QTUdpReader<mavlink_gpio_t>("gpio", udp);
    QDataPortInterface *pcmd_udp = new QTUdpReader<mavlink_position_cmd_t>("position cmd", udp);

    udp->addPort(gpio_udp);
    udp->addPort(pcmd_udp);
    //udp->show();

    QExternalPortDialog *d = new QExternalPortDialog("Command port");
    d->addPort(csv,"csv");
    d->addPort(udp,"udp");
    d->show();

    Listener l;
    QObject::connect(d,&QExternalPortDialog::commands,&l,&Listener::message_received);

    return a.exec();
}
