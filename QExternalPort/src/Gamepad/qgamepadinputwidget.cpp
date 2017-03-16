#include "qgamepadinputwidget.h"

QGamepadInputWidget::QGamepadInputWidget(QString name, QWidget *parent) :
    QInputWidget(name,parent),
    _gamepads(new QComboBox())
{
    layout()->addWidget(_gamepads);
    QObject::connect(QGamepadManager::instance(),&QGamepadManager::gamepadConnected,this,&QGamepadInputWidget::gamepadConnected);
}

int QGamepadInputWidget::currentDeviceID()
{
    return _gamepads->currentData().toInt();
}

bool QGamepadInputWidget::update(int deviceID, int buttonID, double value)
{
    QGamepadButton b(deviceID, buttonID);
    b.setValue(value);

    for(int i=0; i<ports.size(); i++){
        QGamepadCommand *c = dynamic_cast<QGamepadCommand*>(ports[i]);
        c->cmdWidget()->setValue(b);
    }
    return true;
}

void QGamepadInputWidget::gamepadConnected(int deviceID)
{
    QGamepad g(deviceID);
    if(g.name().isEmpty()){
        _gamepads->addItem("Gamepad " + QString::number(g.deviceId()),QVariant(deviceID));
    } else {
        _gamepads->addItem(g.name(),QVariant(deviceID));
    }
}

void QGamepadInputWidget::axisEvent(int deviceID, QGamepadManager::GamepadAxis axis, double value)
{
    if(deviceID == currentDeviceID())
        emit valueChanged(QGamepadButton::buttonID(axis),value);
}

void QGamepadInputWidget::buttonEvent(int deviceID, QGamepadManager::GamepadButton button, double value)
{
    if(deviceID == currentDeviceID())
        emit valueChanged(QGamepadButton::buttonID(button),value);
}





