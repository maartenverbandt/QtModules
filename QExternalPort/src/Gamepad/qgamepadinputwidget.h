#ifndef QGAMEPADINPUTWIDGET_H
#define QGAMEPADINPUTWIDGET_H

#include <qinputwidget.h>
#include <qconfiguredgamepad.h>
#include <qcombobox.h>

class QGamepadInputWidget : public QInputWidget
{
public:
    QGamepadInputWidget(QString name, QWidget *parent = 0);

    virtual QList<QVariant> read();
    QConfiguredGamepad* gamepad();
    void discover();

private:
    QConfiguredGamepad* _gamepad;
    QComboBox *b;

};

#endif // QGAMEPADINPUTWIDGET_H
