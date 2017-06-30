#ifndef QGAMEPADINPUTWIDGET_H
#define QGAMEPADINPUTWIDGET_H

#include <QGamepad>
#include <QGamepadManager>
#include <QComboBox>
#include <qinputwidget.h>
#include <qgamepadbutton.h>
#include <qgamepadcommand.h>

class QGamepadInputWidget : public QInputWidget
{
public:
    QGamepadInputWidget(QString name, QWidget *parent = 0);

private:
    QComboBox *_gamepads;
    int currentDeviceID();
    bool update(int deviceID, int buttonID, double value);

public slots:
    void gamepadConnected(int deviceID);
    void axisEvent(int deviceID, QGamepadManager::GamepadAxis axis, double value);
    void buttonEvent(int deviceID, QGamepadManager::GamepadButton button, double value);

signals:
    void valueChanged(int button, double value);

};

#endif // QGAMEPADINPUTWIDGET_H
