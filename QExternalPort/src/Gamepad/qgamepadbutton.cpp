#include "qgamepadbutton.h"

const QString QGamepadButton::name(QGamepadManager::GamepadAxis axis)
{
    switch(axis){
    case QGamepadManager::AxisLeftX: return "Left X";
    case QGamepadManager::AxisLeftY: return "Left Y";
    case QGamepadManager::AxisRightX: return "Right X";
    case QGamepadManager::AxisRightY: return "Right Y";
    case QGamepadManager::AxisInvalid: return "Invalid";
    }
}

const QString QGamepadButton::name(QGamepadManager::GamepadButton button)
{
    switch(button){
    case QGamepadManager::buttonA: return "Button A";
    case QGamepadManager::buttonB: return "Button B";
    case QGamepadManager::buttonX: return "Button X";
    case QGamepadManager::buttonY: return "Button Y";
    //default
    }
}

QGamepadButton::QGamepadButton(int device_id, int button_id, QObject *parent) :
    QObject(parent),
    _device_id(device_id),
    _button_id(button_id),
    _value(0)
{
    setObjectName(name);
}

int QGamepadButton::deviceID()
{
    return _device_id;
}

int QGamepadButton::buttonID()
{
    return _button_id;
}

double QGamepadButton::value()
{
    return _value;
}

void QGamepadButton::setValue(double value)
{
    _value = value;
}
