#include "qgamepadbutton.h"

QGamepadButton::QGamepadButton(button_id_t id, QString name, QObject *parent) :
    QObject(parent),
    _id(id),
    _value(0)
{
    setObjectName(name);
}

QGamepadButton::button_id_t QGamepadButton::id()
{
    return _id;
}

double QGamepadButton::value()
{
    return _value;
}

void QGamepadButton::setValue(double value)
{
    _value = value;
}
