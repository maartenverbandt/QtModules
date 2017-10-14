#include "qparameter.h"

QParameter::QParameter(QString name, QObject *parent) :
    QObject(parent), _name(name)
{

}

const QString QParameter::name()
{
    return _name;
}
