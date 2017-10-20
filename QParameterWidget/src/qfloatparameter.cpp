#include "qfloatparameter.h"

QFloatParameter::QFloatParameter(QString name, int offset, float value, QObject *parent) :
    QParameter(name, offset, parent), _value(value)
{

}

const QString QFloatParameter::valueString()
{
    return QString::number(_value);
}

void QFloatParameter::setValue(const QString value)
{
    bool ok;
    float newvalue = value.toFloat(&ok);
    if(ok){
        setValue(newvalue);
    } else {
        qWarning() << "Cannot convert" << value << "to float";
    }
}

void QFloatParameter::setValue(double value)
{
    _value = value;
}

float QFloatParameter::value()
{
    return _value;
}

int QFloatParameter::type()
{
    return QParameter::FLOAT;
}
