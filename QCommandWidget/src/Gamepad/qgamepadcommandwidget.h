#ifndef QGAMEPADINPUTWIDGET_H
#define QGAMEPADINPUTWIDGET_H

#include <QGamepad>
#include <QGamepadManager>
#include <QComboBox>
#include <qtypecommandwidget.h>
#include <qgamepadcommanddatanodewidget.h>

/*TODO: avoid up and downcasting from QTypeCommandInterface to QGamepadCommandDataNodeWidget */

class QGamepadCommandWidget : public QTypeCommandWidget
{
public:
    QGamepadCommandWidget(QString name, QWidget *parent = 0);

private:
    QComboBox *_gamepads;
    QList<QGamepadCommandDataNodeWidget *> _commands;

    int currentDeviceID();

public slots:
    void gamepadConnected(int deviceID);
    void axisEvent(int deviceID, QGamepadManager::GamepadAxis axis, double value);
    void buttonEvent(int deviceID, QGamepadManager::GamepadButton button, double value);

};

#endif // QGAMEPADINPUTWIDGET_H
