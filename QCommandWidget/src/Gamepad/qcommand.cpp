#include "qcommand.h"

QCommand::QCommand(QString name, QWidget *parent) :
    QWidget(parent),
    _master_device(-1),
    _button(QGamepadButton::Disabled())
{
    setObjectName(name);
    setup();
}

double QCommand::value()
{
    return _button.value();
}

QGamepadButton *QCommand::button()
{
    return &_button;
}

void QCommand::setup()
{
    QHBoxLayout *l = new QHBoxLayout(this);
    setLayout(l);
    l->addWidget(new QLabel(objectName(),this));
    _button_box = makeButtonBox(this);
    l->addWidget(_button_box,1);

    QObject::connect(_button_box,static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),this,&QCommand::buttonIdChanged);
}

QComboBox *QCommand::makeButtonBox(QWidget *parent)
{
    QList<QString> buttonnames = QGamepadButton::axisNames();
    buttonnames.append(QGamepadButton::buttonNames());
    buttonnames.insert(0,"Disabled");
    QList<int> buttonids = QGamepadButton::axisIDs();
    buttonids.append(QGamepadButton::buttonIDs());
    buttonids.insert(0,-1);

    QComboBox *button_box = new QComboBox(parent);
    for(int i = 0; i<buttonnames.size(); i++){
        button_box->addItem(buttonnames[i],QVariant(buttonids[i]));
    }

    return button_box;
}

void QCommand::buttonIdChanged(int index)
{
    _button.setButtonID(_button_box->currentData().toInt());
    _button.setDeviceID(_master_device);
    _button.setValue(0);
}

void QCommand::masterDeviceChanged(int device_id)
{
    _master_device = device_id;
}


