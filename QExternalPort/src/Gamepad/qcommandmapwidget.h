#ifndef QGAMEPADCOMMANDWIDGET_H
#define QGAMEPADCOMMANDWIDGET_H

#include <QWidget>
#include <QSignalMapper>
#include <qcommandmap.h>
#include <qgamepadinputwidget.h>


namespace Ui {
class QCommandMapWidget;
}

class QCommandMapWidget : public QWidget, public QCommandMap
{
    Q_OBJECT

public:
    explicit QCommandMapWidget(QString name, QGamepadInputWidget *parent = 0);
    ~QCommandMapWidget();

    bool enabled();

    void setup();

private:
    Ui::QCommandMapWidget *ui;
    QSignalMapper *_boxmapper;

    QList<QGamepadButton*> _buttons;
    QList<QComboBox*> _boxes;

    QGamepadButton* button(QString name);

private slots:
    void boxChanged(int id);

};

#endif // QGAMEPADCOMMANDWIDGET_H
