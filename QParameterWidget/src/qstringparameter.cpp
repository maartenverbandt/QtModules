#include "qstringparameter.h"

QStringParameter::QStringParameter(QString name, int offset, QString value, QObject *parent) :
    QParameter(name, offset, parent), _value(value)
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

QString QStringParameter::value()
{
    return _value;
}
