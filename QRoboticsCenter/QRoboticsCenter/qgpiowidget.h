#ifndef QGPIOWIDGET_H
#define QGPIOWIDGET_H

#include <QWidget>
#include <QBoxLayout>
#include <qrunningplot.h>
#include <mavlink.h>

#define QGPIOWIDGET_IOCOUNT 8

namespace Ui {
class QGPIOWidget;
}

class QGPIOWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QGPIOWidget(QWidget *parent = 0);
    ~QGPIOWidget();

private:
    Ui::QGPIOWidget *ui;

    QBoxLayout* horizontal_layout;
    QGridLayout* grid_layout_checkbox;
    QGridLayout* grid_layout_spinbox;
    QRunningPlot* plot;
    QPushButton* set_button;
    QCheckBox checkboxs[2*QGPIOWIDGET_IOCOUNT];
    QDoubleSpinBox spinboxs[2*QGPIOWIDGET_IOCOUNT];

    int integer_list[QGPIOWIDGET_IOCOUNT];
    double double_list[QGPIOWIDGET_IOCOUNT];

    double _time;

public slots:
    void mavlinkMsgReceived(mavlink_message_t msg);
    void timerEvent(QTimerEvent *event);

private slots:
    void checkCheckboxs(int i = 0);
    void sendGPIO();

signals:
    void mavlinkMsgSend(mavlink_message_t msg);
};

#endif // QGPIOWIDGET_H
