#include "qmicroosanalyzer.h"
#include "ballbotdialog.h"
#include "ballbotconfigdialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QMicroOSAnalyzer* w = new QMicroOSAnalyzer();
    w->show();

    BallbotDialog* b = new BallbotDialog();
    b->show();

    BallbotConfigDialog* c = new BallbotConfigDialog();
    c->show();

    return a.exec();
}
