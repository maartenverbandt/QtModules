#include "qgamepadinputwidget.h"
#include <QtGamepad/QGamepadManager>

QGamepadInputWidget::QGamepadInputWidget(QString name, QWidget *parent) :
    QInputWidget(name,parent),
    b(new QComboBox())
{
    layout()->addWidget(b);
    discover();
}

QList<QVariant> QGamepadInputWidget::read()
{
    _gamepad->readAll();
    return QInputWidget::read();
}

void QGamepadInputWidget::discover()
{
    auto gamepads = QGamepadManager::instance()->connectedGamepads();

    if(gamepads.size() >= 1){
        _gamepad = new QConfiguredGamepad(gamepads[0],this);
        if(_gamepad->name().isEmpty()){
            b->addItem("Gamepad " + QString::number(_gamepad->deviceId()));
        } else {
            b->addItem(_gamepad->name());
        }
    }
}

QConfiguredGamepad *QGamepadInputWidget::gamepad()
{
    return _gamepad;
}




