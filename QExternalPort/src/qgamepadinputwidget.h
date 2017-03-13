#ifndef QGAMEPADINPUTWIDGET_H
#define QGAMEPADINPUTWIDGET_H

#include <qinputwidget.h>
#include <qconfiguredgamepad.h>

class QGamepadInputWidget : public QInputWidget
{
public:
    QGamepadInputWidget(QString name, QWidget *parent = 0);

    virtual QList<QVariant> read();

private:
    QConfiguredGamepad* _gamepad;

};

#endif // QGAMEPADINPUTWIDGET_H
