#include "qstringparameter.h"

QStringParameter::QStringParameter(QString name, QString value, QObject *parent) :
    QParameter(name, parent), _value(value)
{

}

const QString QStringParameter::valueString()
{
    return _value;
}

void QStringParameter::setValue(const QString value)
{
    _value = value;
}

int QStringParameter::type()
{
    return QParameter::STRING;
}
