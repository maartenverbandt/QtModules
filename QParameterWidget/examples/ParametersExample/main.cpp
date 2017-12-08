#include <QtGui>
#include <qintegerparameter.h>
#include <qfloatparameter.h>
#include <qparameterdatanodewidget.h>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QIntegerParameter _parameter1("param1", 0, 12);
    QIntegerParameter _parameter2("param2", 4, -40);
    QFloatParameter _parameter3("param3", 8, -40.0);

    QParameterDataNodeWidget emulator(0);
    emulator.add(_parameter1);
    emulator.add(_parameter2);
    emulator.add(_parameter3);
    emulator.w()->show();

    QParameterDataNodeWidget gui(0);
    gui.w()->show();
    gui.connectTo(&emulator);

    return a.exec();
}
