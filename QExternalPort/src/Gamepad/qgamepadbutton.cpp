#include "qgamepadbutton.h"

const QMap<QGamepadManager::GamepadAxis,QString> QGamepadButton::_axis_map{{QGamepadManager::AxisLeftX,"Left X"},
                                                                           {QGamepadManager::AxisLeftY,"Left Y"},
                                                                           {QGamepadManager::AxisRightX,"Right X"},
                                                                           {QGamepadManager::AxisRightY,"Right Y"}};

const QMap<QGamepadManager::GamepadButton,QString> QGamepadButton::_button_map   {{QGamepadManager::ButtonA,"Button A"},
                                                                                        {QGamepadManager::ButtonB,"Button B"},
                                                                                        {QGamepadManager::ButtonX,"Button X"},
                                                                                        {QGamepadManager::ButtonY,"Button Y"}};

const QString QGamepadButton::name(QGamepadManager::GamepadAxis axis)
{
    return _axis_map[axis];
}

const QString QGamepadButton::name(QGamepadManager::GamepadButton button)
{
    return _button_map[button];
}

int QGamepadButton::buttonID(QGamepadManager::GamepadAxis axis)
{
    return (int)axis;
}

int QGamepadButton::buttonID(QGamepadManager::GamepadButton button)
{
    return 1000+(int)button;
}

QList<QString> QGamepadButton::axisNames()
{
    return _axis_map.values();
}

QList<int> QGamepadButton::axisIDs()
{
    QList<int> list;
    QList<QGamepadManager::GamepadAxis> keys = _axis_map.keys();
    QListIterator<QGamepadManager::GamepadAxis> i(keys);
    while(i.hasNext())
        list.append(buttonID(i.next()));
    return list;
}

QList<QString> QGamepadButton::buttonNames()
{
    return _button_map.values();
}

QList<int> QGamepadButton::buttonIDs()
{
    QList<int> list;
    QList<QGamepadManager::GamepadButton> keys = _button_map.keys();
    QListIterator<QGamepadManager::GamepadButton> i(keys);
    while(i.hasNext())
        list.append(buttonID(i.next()));
    return list;
}

const QMap<QGamepadManager::GamepadAxis, QString> QGamepadButton::axisMap()
{
    return _axis_map;
}

const QMap<QGamepadManager::GamepadButton, QString> QGamepadButton::buttonMap()
{
    return _button_map;
}

QGamepadButton::QGamepadButton(int device_id, int button_id) :
    _device_id(device_id),
    _button_id(button_id),
    _value(0)
{

}

QGamepadButton QGamepadButton::Disabled()
{
    return QGamepadButton(-1,-1);
}

bool QGamepadButton::isDisabled()
{
    return (deviceID() == -1) && (buttonID() == -1);
}

int QGamepadButton::deviceID() const
{
    return _device_id;
}

void QGamepadButton::setDeviceID(int device_id)
{
    _device_id = device_id;
}

int QGamepadButton::buttonID() const
{
    return _button_id;
}

void QGamepadButton::setButtonID(int button_id)
{
    _button_id = button_id;
}

double QGamepadButton::value()
{
    return _value;
}

void QGamepadButton::setValue(double value)
{
    _value = value;
}

bool QGamepadButton::operator==(const QGamepadButton &b)
{
    return (_button_id==b._button_id);
}
