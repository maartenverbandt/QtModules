#ifndef QGAMEPADBUTTON_H
#define QGAMEPADBUTTON_H

#include <QObject>
#include <QtGamepad/QGamepadManager>

class QGamepadButton : public QObject
{
    Q_OBJECT

public:
    explicit QGamepadButton(int device_id, int button_id, QObject *parent = 0);

    int deviceID();
    int buttonID();
    double value();
    void setValue(double value);

    const static QString name(QGamepadManager::GamepadAxis axis);
    const static QString name(QGamepadManager::GamepadButton button);

private:
    int _device_id;
    int _button_id;
    double _value;

};

#endif // QGAMEPADBUTTON_H
