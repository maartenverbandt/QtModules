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

    QInputWidget *csv = new QInputWidget("CSV",0);
    csv->addPort(new QGpioCsvReader(csv));
    csv->addPort(new QPositionCmdCsvReader(csv));

    QInputWidget *udp = new QInputWidget("UDP",0);
    udp->addPort(new QGpioUdpReader(udp));
    udp->addPort(new QPositionCmdUdpReader(udp));

    QExternalPortDialog *d = new QExternalPortDialog("Command port");
    d->addInputWidget(csv);
    d->addInputWidget(udp);
    d->show();

    Listener l;
    QObject::connect(d,&QExternalPortDialog::commands,&l,&Listener::message_received);

    return a.exec();
}
