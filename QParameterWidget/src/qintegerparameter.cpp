#include "qintegerparameter.h"

QIntegerParameter::QIntegerParameter(QString name, int offset, int value, QObject *parent) :
    QParameter(name, offset, parent), _value(value)
{

}

const QString QIntegerParameter::valueString()
{
    return QString::number(_value);
}

void QIntegerParameter::setValue(const QString value)
{
    bool ok;
    int newvalue = value.toInt(&ok);
    if(ok){
        setValue(newvalue);
    } else {
        qWarning() << "Cannot convert" << value << "to integer";
    }
}

void QIntegerParameter::setValue(int value)
{
    _value = value;
}

int QIntegerParameter::value()
{
    return _value;
}

int QIntegerParameter::type()
{
    return QParameter::INTEGER;
}
