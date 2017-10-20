#include "qparameter.h"

QParameter::QParameter(QString name, int offset, QObject *parent) :
    QObject(parent), _name(name), _offset(offset)
{

}

const QString QParameter::name()
{
    return _name;
}

const int QParameter::offset()
{
    return _offset;
}
