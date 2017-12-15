#include "qgamepadentry.h"

QGamepadEntry::QGamepadEntry(const QString &name, QWidget *parent) : QWidget(parent)
{
    _name->setText(name);
    _gain->setRange(0,1e6);
    _gain->setValue(1.0);
    _reverse->setCheckable(true);
    _reverse->setChecked(false);
    _configure->setCheckable(true);
    _configure->setChecked(false);

    setLayout(new QHBoxLayout());
    layout()->setMargin(0);
    layout()->addWidget(_name);
    layout()->addWidget(_axis_label);
    layout()->addWidget(_gain);
    layout()->addWidget(_reverse);
    layout()->addWidget(_configure);
}

QPushButton *QGamepadEntry::confButton()
{
    return _configure;
}

double QGamepadEntry::value()
{
    return _value;
}

void QGamepadEntry::compute(double value)
{
    _value = _gain->value()*value;
    if(_reverse->isChecked()) {
        _value = -_value;
    }
}

void QGamepadEntry::configure(int axis, double value)
{
    _axis = axis;
    if(value < 0) { _reverse->setChecked(true); }
    else { _reverse->setChecked(false); }
    switch(axis) {
        case QGamepadManager::AxisLeftX: { _axis_label->setText("LeftX"); break; }
        case QGamepadManager::AxisLeftY: { _axis_label->setText("LeftY"); break; }
        case QGamepadManager::AxisRightX: { _axis_label->setText("RightX"); break; }
        case QGamepadManager::AxisRightY: { _axis_label->setText("RightY"); break; }
        default: _axis_label->setText("axis " + QString::number(axis));
    }
}

void QGamepadEntry::on_axis_changed(int axis, double value)
{
    if(_configure->isChecked()) {
        configure(axis,value);
        _configure->setChecked(false);
    }
    if(_axis == axis) {
        compute(value);
    }
}
