#include "qcommandgamepadwidget.h"

QCommandGamepadWidget::QCommandGamepadWidget(QString name, QWidget *parent) :
    QTypeCommandWidget(name,parent),
    _gamepads(new QComboBox())
{
    layout()->addWidget(_gamepads);

    QList<int> g = QGamepadManager::instance()->connectedGamepads();
    QListIterator<int> i(g);
    while(i.hasNext())
        gamepadConnected(i.next());

    QObject::connect(QGamepadManager::instance(),&QGamepadManager::gamepadConnected,this,&QCommandGamepadWidget::gamepadConnected);
    QObject::connect(QGamepadManager::instance(),&QGamepadManager::gamepadAxisEvent,this,&QCommandGamepadWidget::axisEvent);
    QObject::connect(QGamepadManager::instance(),&QGamepadManager::gamepadButtonPressEvent,this,&QCommandGamepadWidget::buttonEvent);
    //QObject::connect(QGamepadManager::instance(),&QGamepadManager::gamepadButtonReleaseEvent,this,&QGamepadInputWidget::buttonEvent);

}

int QCommandGamepadWidget::currentDeviceID()
{
    return _gamepads->currentData().toInt();
}

bool QCommandGamepadWidget::update(int deviceID, int buttonID, double value)
{
    QGamepadButton b(deviceID, buttonID);
    b.setValue(value);

    for(int i=0; i<_ports.size(); i++){
        QGamepadCommand *c = dynamic_cast<QGamepadCommand*>(_ports[i]);
        c->cmdWidget()->setValue(b);
    }
    return true;
}

void QCommandGamepadWidget::gamepadConnected(int deviceID)
{
    QGamepad g(deviceID);
    if(g.name().isEmpty()){
        _gamepads->addItem("Gamepad " + QString::number(g.deviceId()),QVariant(deviceID));
    } else {
        _gamepads->addItem(g.name(),QVariant(deviceID));
    }
}

void QCommandGamepadWidget::axisEvent(int deviceID, QGamepadManager::GamepadAxis axis, double value)
{
    if(deviceID == currentDeviceID())
        update(deviceID, QGamepadButton::buttonID(axis), value);
}

void QCommandGamepadWidget::buttonEvent(int deviceID, QGamepadManager::GamepadButton button, double value)
{
    if(deviceID == currentDeviceID())
        update(deviceID, QGamepadButton::buttonID(button), value);
}
