#ifndef QCOMMAND_H
#define QCOMMAND_H

#include <QWidget>
#include <QComboBox>
#include <QHBoxLayout>
#include <QLabel>
#include <qgamepadbutton.h>

class QCommand : public QWidget
{
    Q_OBJECT
public:
    explicit QCommand(QString name, QWidget *parent = 0);

    double value();
    QGamepadButton* button();

private:
    int _master_device;
    QGamepadButton _button;

    void setup();

    QComboBox* _button_box;
    static QComboBox* makeButtonBox(QWidget *parent = 0);

private slots:
    void buttonIdChanged(int index);

public slots:
    void masterDeviceChanged(int device_id);

};

#endif // QCOMMAND_H
