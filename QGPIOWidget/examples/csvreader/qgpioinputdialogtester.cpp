#include "qgpioinputdialogtester.h"
#include "ui_qgpioinputdialogtester.h"

QGPIOInputDialogTester::QGPIOInputDialogTester(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QGPIOInputDialogTester)
{
    ui->setupUi(this);
}

QGPIOInputDialogTester::~QGPIOInputDialogTester()
{
    delete ui;
}

void QGPIOInputDialogTester::printGpio(QGPIOWidget::gpio_t gpio)
{
    QVector<float> floats(8);
    QVector<int> ints(4);
    memcpy(floats.data(),gpio.floats,32);
    memcpy(ints.data(),gpio.ints,16);

    qDebug() << gpio.time << floats << ints;
}
