#include "mainwindow.h"
#include <QApplication>

#include <qoutputwidget.h>
#include <qoutputdialog.h>
#include <qtudpsender.h>
#include <qgpiogenerator.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();


    QOutputDialog *d = new QOutputDialog("somename");
    QOutputWidget *o = new QOutputWidget("UDP");
    o->addSender(new QGpioUdpSender(o));
    d->addOutputWidget(o);
    d->show();

    QGpioGenerator *g = new QGpioGenerator(0);

    QObject::connect(g,&QGpioGenerator::sendPacket,d,&QOutputDialog::sendPackets);

    return a.exec();
}
