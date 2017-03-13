#include "qconfiguredgamepad.h"

QConfiguredGamepad::QConfiguredGamepad(int deviceId, QObject *parent) :
    QGamepad(deviceId, parent)
{    
    _buttons.append(QGamepadButton::Disabled());
    _buttons.append(QGamepadButton::LeftX());
    _buttons.append(QGamepadButton::LeftY());
    _buttons.append(QGamepadButton::RightX());
    _buttons.append(QGamepadButton::RightY());
}

QList<QGamepadButton *> QConfiguredGamepad::buttons()
{
    return _buttons;
}

void QConfiguredGamepad::readAll()
{
    for(int i=0; i<_buttons.size(); i++)
        _buttons[i]->setValue(getValue(_buttons[i]->id()));
}

double QConfiguredGamepad::getValue(QGamepadButton::button_id_t id)
{
    switch(id){
    case QGamepadButton::axisLeftX: return axisLeftX();
    case QGamepadButton::axisLeftY: return axisLeftY();
    case QGamepadButton::axisRightX: return axisRightX();
    case QGamepadButton::axisRightY: return axisRightY();
    default: return 0;
    }
}
