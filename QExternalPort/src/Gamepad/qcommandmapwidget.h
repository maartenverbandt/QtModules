#ifndef QGAMEPADCOMMANDWIDGET_H
#define QGAMEPADCOMMANDWIDGET_H

#include <QWidget>
#include <QSignalMapper>
#include <QComboBox>
#include <qcommandmap.h>
#include <qgamepadinputwidget.h>

namespace Ui {
class QCommandMapWidget;
}

class QGamepadInputWidget;

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
    QList<QComboBox*> _boxes;

private slots:
    void boxChanged(int id);

};

#endif // QGAMEPADCOMMANDWIDGET_H
