#ifndef QGPIOPORTDIALOG_H
#define QGPIOPORTDIALOG_H

#include <qexternalportdialog.h>
#include <qgpiofileport.h>

class QGPIOPortDialog : public QExternalPortDialog
{
public:
    QGPIOPortDialog(QWidget *parent);

    mavlink_gpio_t getGpioPacket();

private:
    QGPIOFilePort* _file_port;

};

#endif // QGPIOPORTDIALOG_H
