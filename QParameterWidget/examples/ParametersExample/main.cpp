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
    QIntegerParameter _parameter1("param1", 12);
    QIntegerParameter _parameter2("param2", -40);
    QFloatParameter _parameter3("param3", -40.0);

    _parameters.addParameter(&_parameter1);
    _parameters.addParameter(&_parameter2);
    _parameters.addParameter(&_parameter3);

    QParameterTableWidget w(&_parameters);
    w.show();

    return a.exec();
}
