#ifndef QCONFIGUREDGAMEPAD_H
#define QCONFIGUREDGAMEPAD_H

#include <QtGamepad/QGamepad>
#include <qgamepadbutton.h>

class QConfiguredGamepad : public QGamepad
{
public:
    QConfiguredGamepad(int deviceId, QObject *parent = 0);
    void readAll();

    QList<QGamepadButton*> buttons();

private:
    double getValue(QGamepadButton::button_id_t id);

    QList<QGamepadButton*> _buttons;


};

#endif // QCONFIGUREDGAMEPAD_H
