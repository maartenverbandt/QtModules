#include "qgamepadcommandwidget.h"

QGamepadCommandWidget::QGamepadCommandWidget(QString name, QWidget *parent) :
    QTypeCommandWidget(name,parent),
    _gamepads(new QComboBox())
{
    addWidget(_gamepads);

    QList<int> g = QGamepadManager::instance()->connectedGamepads();
    QListIterator<int> i(g);
    while(i.hasNext()) {
        gamepadConnected(i.next());
    }

    QObject::connect(QGamepadManager::instance(),&QGamepadManager::gamepadConnected,this,&QGamepadCommandWidget::gamepadConnected);
    QObject::connect(QGamepadManager::instance(),&QGamepadManager::gamepadAxisEvent,this,&QGamepadCommandWidget::axisEvent);
    QObject::connect(QGamepadManager::instance(),&QGamepadManager::gamepadButtonPressEvent,this,&QGamepadCommandWidget::buttonEvent);
    //QObject::connect(QGamepadManager::instance(),&QGamepadManager::gamepadButtonReleaseEvent,this,&QGamepadInputWidget::buttonEvent);

}

int QGamepadCommandWidget::currentDeviceID()
{
    return _gamepads->currentData().toInt();
}

void QGamepadCommandWidget::gamepadConnected(int deviceID)
{
    qDebug() << "gamepad connected";
    QGamepad g(deviceID);
    if(g.name().isEmpty()){
        _gamepads->addItem("Gamepad " + QString::number(g.deviceId()),QVariant(deviceID));
    } else {
        _gamepads->addItem(g.name(),QVariant(deviceID));
    }
}

void QGamepadCommandWidget::axisEvent(int deviceID, QGamepadManager::GamepadAxis axis, double value)
{
    if(deviceID == currentDeviceID()) {
        QListIterator<QTypeCommandInterface *> i(_ports);
        while(i.hasNext()) {
            static_cast<QGamepadCommandDataNodeWidget *>(i.next())->on_axis_changed(axis,value);
        }
    }
}

void QGamepadCommandWidget::buttonEvent(int deviceID, QGamepadManager::GamepadButton button, double value)
{
    qDebug() << "button event: " << button << value;
    //if(deviceID == currentDeviceID())
    //do nothing
}
