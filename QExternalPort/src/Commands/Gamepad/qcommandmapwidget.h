#ifndef QGAMEPADCOMMANDWIDGET_H
#define QGAMEPADCOMMANDWIDGET_H

#include <QWidget>
#include <QSignalMapper>
#include <QComboBox>
#include <qcommand.h>
#include <QDebug>

namespace Ui {
class QCommandMapWidget;
}

class QCommandMapWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QCommandMapWidget(QString name, QWidget *parent = 0);
    ~QCommandMapWidget();

    bool enabled();

    void add(QString name);
    virtual void add(QCommand *command);
    double value(QString command);
    bool setValue(QGamepadButton button);
    void setup();

private:
    Ui::QCommandMapWidget *ui;

    QMap<QString,QCommand*> _map;

public slots:
    void masterDeviceChanged(int device_id);

};

#endif // QGAMEPADCOMMANDWIDGET_H
