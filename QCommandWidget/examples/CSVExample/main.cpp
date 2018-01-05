#include <QApplication>
#include <qtypecommandwidget.h>
#include <qgpiocsvcommand.h>
#include <qpositioncmdcsvcommand.h>
#include <qcommandwidget.h>
#include <listener.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QCoreApplication::setOrganizationName("RobSoft");
    QCoreApplication::setApplicationName("CSVExample");

    QTypeCommandWidget *csv = new QTypeCommandWidget("CSV",0);
    csv->add(new QGpioCsvCommand(csv));
    csv->add(new QPositionCmdCsvCommand(csv));

    QCommandWidget *d = new QCommandWidget(0);
    d->add(csv);
    d->show();

    Listener *l = new Listener(0);
    d->transmitTo(l);

    d->restoreState("csv_test");
    QObject::connect(&a,&QApplication::aboutToQuit,[=](){d->saveState("csv_test");});

    return a.exec();
}
