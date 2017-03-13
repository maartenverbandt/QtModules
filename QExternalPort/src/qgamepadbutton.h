#ifndef QGAMEPADBUTTON_H
#define QGAMEPADBUTTON_H

#include <QObject>

class QGamepadButton : public QObject
{
    Q_OBJECT
public:
    explicit QGamepadButton(button_id_t id, QString name, QObject *parent = 0);

    button_id_t id();
    double value();
    void setValue(double value);

    typedef enum button_id_t {
        axisLeftX,
        axisLeftY,
        axisRightX,
        axisRightY,
        buttonL1,
        buttonL2,
        buttonL3,
        buttonR1,
        buttonR2,
        buttonR3,
        buttonA,
        buttonB,
        buttonX,
        buttonY,
        buttonLeft,
        buttonRight,
        buttonUp,
        buttonDown,
        disabled
    } button_id_t;

    static QGamepadButton LeftX(QObject* parent = 0){ return QGamepadButton(axisLeftX, "Left X", parent); }
    static QGamepadButton LeftY(QObject* parent = 0){ return QGamepadButton(axisLeftY, "Left Y", parent); }

private:
    button_id_t _id;
    double _value;

};

#endif // QGAMEPADBUTTON_H
