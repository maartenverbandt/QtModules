#ifndef QGPIORECORDER_H
#define QGPIORECORDER_H

#include <qabstractrecorder.h>
#include <qgpiowidget.h>
#include <mavlink.h>

class QGPIORecorder : public QAbstractRecorder
{
    Q_OBJECT
public:
    QGPIORecorder(QGPIOWidget *gpio, QObject* parent = 0);

private:
    QFile* _log;
    QGPIOWidget* _gpio;

    QString createHeader();
    QString createFooter();

public slots:
    void gpioReceived(mavlink_gpio_t gpio);
    //void setLabels(QStringList); //OBSOLETE
    void startRecording();
    void stopRecording();

};

#endif // QGPIORECORDER_H
