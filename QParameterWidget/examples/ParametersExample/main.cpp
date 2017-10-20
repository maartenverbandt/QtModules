#include <QtGui>
#include <qparametermanager.h>
#include <qintegerparameter.h>
#include <qfloatparameter.h>
#include <qparametertablewidget.h>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QParameterManager _parameters;
    QIntegerParameter _parameter1("param1", 0, 12);
    QIntegerParameter _parameter2("param2", 4, -40);
    QFloatParameter _parameter3("param3", 8, -40.0);

    _parameters.addParameter(&_parameter1);
    _parameters.addParameter(&_parameter2);
    _parameters.addParameter(&_parameter3);

    QParameterTableWidget emulator(&_parameters);
    emulator.show();

    QParameterManager _parameters2;
    QParameterTableWidget gui(&_parameters2);
    gui.show();

    QParameterManager::connect(&_parameters, &_parameters2);

    return a.exec();
}
