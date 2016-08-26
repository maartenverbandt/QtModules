#ifndef QGPIOWIDGET_H
#define QGPIOWIDGET_H

#include <QWidget>
#include <QBoxLayout>
#include <qrunningplot.h>
#include <mavlink.h>

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

    enum qgpiowidget_event_t {
        BUTTONX_PRESSED = 1000
    };

public:
    explicit QGPIOWidget(QWidget *parent = 0);
    ~QGPIOWidget();

    QVector<float> getOutDoubles();
    QVector<int> getOutInts();
    QVector<float> getInDoubles();
    QVector<int> getInInts();
    void setInDoubles(QVector<float> doubles);
    void setInInts(QVector<int> ints);

private:
    Ui::QGPIOWidget *ui;

    QGridLayout* grid_layout_checkbox;
    QCheckBox checkboxs[QGPIOWIDGET_IOCOUNT];
#ifndef QGPIOWIDGET_LABELLOCK
    QLineEdit checkboxlabels[QGPIOWIDGET_IOCOUNT];
#else
    QLabel checkboxlabels[QGPIOWIDGET_IOCOUNT];
#endif

    QRunningPlot* plot;

    QGridLayout* grid_layout_spinbox;
    QDoubleSpinBox spinboxs[QGPIOWIDGET_IOCOUNT];

#ifndef QGPIOWIDGET_LABELLOCK
    QLineEdit spinboxlabels[QGPIOWIDGET_IOCOUNT];
#else
    QLabel spinboxlabels[QGPIOWIDGET_IOCOUNT];
#endif
    QPushButton* set_button;

    QGridLayout* grid_layout_buttons;
    QButtonGroup buttons;

    QVector<float> double_list;
    QVector<int> integer_list;

    double _time;
    bool _paused;

    void loadSettings();
    void saveSettings();
    void setLabels();

    bool running();
    bool paused();

public slots:
    void mavlinkMsgReceived(mavlink_message_t msg);
    void timerEvent(QTimerEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void setGPIO(QVector<float> d, QVector<int> i);
    void setPrint(QString text);
    void inputLabelsSend();

private slots:
    void checkCheckboxs(int i = 0);
    void sendGPIO();
    void sendEvent(uint16_t event);
    void sendButtonEvent(int id);

signals:
    void mavlinkMsgSend(mavlink_message_t msg);

    void eventButtonPressed(int b);
    void gpioSet(QVector<float> d, QVector<int> i);
    void inputLabelsSet(QStringList labels);
};

#endif // QGPIOWIDGET_H
