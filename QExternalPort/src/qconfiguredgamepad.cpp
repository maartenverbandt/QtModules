#include "qconfiguredgamepad.h"

QConfiguredGamepad::QConfiguredGamepad(int deviceId, QObject *parent) :
    QGamepad(deviceId, parent)
{
    //buttons.
}

QList<QGamepadButton *> QConfiguredGamepad::buttons()
{
    return _buttons;
}

void QConfiguredGamepad::readAll()
{
    for(int i=0; i<_buttons.size(); i++)
        _buttons[i]->setValue(value(_buttons[i]->id()));
}

double QConfiguredGamepad::getValue(QGamepadButton::button_id_t id)
{
    switch(id){
    case QGamepadButton::axisLeftX: return _gamepad->axisLeftX();
    case QGamepadButton::axisLeftY: return _gamepad->axisLeftY();
    case QGamepadButton::axisRightX: return _gamepad->axisRightX();
    case QGamepadButton::axisRightY: return _gamepad->axisRightY();
    default: return 0;
}
