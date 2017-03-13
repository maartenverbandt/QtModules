#include "qgamepadinputwidget.h"

QGamepadInputWidget::QGamepadInputWidget(QString name, QWidget *parent) :
    QInputWidget(name,parent)
{

}

QList<QVariant> QGamepadInputWidget::read()
{
    _gamepad->readAll();
    return QInputWidget::read();
}




