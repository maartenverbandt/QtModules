#ifndef QGPIOFILEPORT_H
#define QGPIOFILEPORT_H

#include <qcsvreaderwidget.h>
#include <qgpioportinterface.h>

class QGPIOFilePort : public QObject, public QGPIOPortInterface
{
    Q_OBJECT

public:
    QGPIOFilePort(QObject *parent = 0);

    mavlink_gpio_t getGpioPacket();
    QVariant getPacket();
    QWidget* getWidget();

private:
    QCsvReaderWidget* _csv_reader;

};

#endif // QGPIOFILEPORT_H
