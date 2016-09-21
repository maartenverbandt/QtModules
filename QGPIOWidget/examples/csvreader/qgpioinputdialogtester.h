#ifndef QGPIOINPUTDIALOGTESTER_H
#define QGPIOINPUTDIALOGTESTER_H

#include <QMainWindow>
#include <qgpiowidget.h>

namespace Ui {
class QGPIOInputDialogTester;
}

class QGPIOInputDialogTester : public QMainWindow
{
    Q_OBJECT

public:
    explicit QGPIOInputDialogTester(QWidget *parent = 0);
    ~QGPIOInputDialogTester();

private:
    Ui::QGPIOInputDialogTester *ui;

public slots:
    void printGpio(QGPIOWidget::gpio_t gpio);

};

#endif // QGPIOINPUTDIALOGTESTER_H
