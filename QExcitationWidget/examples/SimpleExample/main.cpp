#include <QtGui>
#include <QApplication>
#include <qexcitationwidget.h>
#include <qexcitationreceiver.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QExcitationWidget *w = new QExcitationWidget(0);
    w->show();

    QExcitationReceiver *r = new QExcitationReceiver(0);
    w->transmitTo(r);

    return a.exec();
}
