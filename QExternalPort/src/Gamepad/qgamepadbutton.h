#ifndef QGAMEPADBUTTON_H
#define QGAMEPADBUTTON_H

#include <QMap>
#include <QtGamepad/QGamepadManager>

class QGamepadButton
{
public:
    QGamepadButton(int device_id = -1, int button_id = -1);
    static QGamepadButton Disabled();
    bool isDisabled();

    int deviceID() const;
    int buttonID() const;
    double value();
    void setValue(double value);
    bool operator==(const QGamepadButton &b);

    static const QString name(QGamepadManager::GamepadAxis axis);
    static const QString name(QGamepadManager::GamepadButton button);
    static int buttonID(QGamepadManager::GamepadAxis axis);
    static int buttonID(QGamepadManager::GamepadButton button);

    static QList<QString> axisNames();
    static QList<int> axisIDs();
    static QList<QString> buttonNames();
    static QList<int> buttonIDs();

    static const QMap<QGamepadManager::GamepadAxis,QString> axisMap();
    static const QMap<QGamepadManager::GamepadButton,QString> buttonMap();

private:
    int _device_id;
    int _button_id;
    double _value;

    static const QMap<QGamepadManager::GamepadAxis,QString> _axis_map;
    static const QMap<QGamepadManager::GamepadButton,QString> _button_map;

};

#endif // QGAMEPADBUTTON_H
