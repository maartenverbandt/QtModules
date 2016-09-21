#ifndef QGPIOWIDGET_H
#define QGPIOWIDGET_H

#include <QWidget>
#include <QBoxLayout>
#include <QLayout>
#include <qrunningplot.h>
#include <mavlink/ballbot_messagesavr/mavlink.h>

#include <qgeneraloutput.h>
#include <qgeneraloutputint.h>
#include <qgeneraloutputfloat.h>
#include <qgeneralinput.h>
#include <qgeneralinputint.h>
#include <qgeneralinputfloat.h>

#define QGPIOWIDGET_FLOAT_COUNT 8
#define QGPIOWIDGET_INT_COUNT   4
#define QGPIOWIDGET_IOCOUNT     12
#define QGPIOWIDGET_BUTTONCOUNT 8

//#define QGPIOWIDGET_LABELLOCK

namespace Ui {
class QGPIOWidget;
}

class QGPIOWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QGPIOWidget(QWidget *parent = 0);
    ~QGPIOWidget();

    void loadSettings();
    void saveSettings();

    typedef struct gpio_t{
        float floats[8];
        int ints[4];
        unsigned int time;
    } gpio_t;

private:
    Ui::QGPIOWidget *ui;

    QGridLayout* _input_layout;
    QGeneralInputFloat* _float_inputs[8];
    QGeneralInputInt* _int_inputs[4];

    QRunningPlot* plot;

    QBoxLayout* _output_layout;
    QGeneralOutputFloat* _float_outputs[8];
    QGeneralOutputInt* _int_outputs[4];
    QPushButton* set_button;

    QGridLayout* grid_layout_buttons;
    QButtonGroup buttons;

    QVector<float> double_list;
    QVector<int> integer_list;

    double _time;
    bool _paused;

    int _plot_timer;
    int _gpio_timer;

    void setLabels();

    bool running();
    bool paused();

public slots:
    void setInput(QGPIOWidget::gpio_t gpio);
    void sendButtonEvent(int id);
    void inputLabelsSend();

    void timerEvent(QTimerEvent *event);
    void keyPressEvent(QKeyEvent *event);

private slots:
    void checkCheckboxs();
    void sendGPIO();

signals:
    void eventButtonPressed(int b);
    void setOutput(QGPIOWidget::gpio_t gpio);
    void inputLabelsSet(QStringList labels);
};

Q_DECLARE_METATYPE(QGPIOWidget::gpio_t)

#endif // QGPIOWIDGET_H
