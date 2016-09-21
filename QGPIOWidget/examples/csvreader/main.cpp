#include "qgpioinputdialogtester.h"
#include <QApplication>
#include <qgpioinputdialog.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QGPIOInputDialogTester w;
    //w.show();
    QGPIOInputDialog d;
    d.show();

    QObject::connect(&d,SIGNAL(setGpioOutput(QGPIOWidget::gpio_t)),&w,SLOT(printGpio(QGPIOWidget::gpio_t)));

    return a.exec();
}
