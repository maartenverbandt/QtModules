#ifndef QGPIOFILEPORT_H
#define QGPIOFILEPORT_H

#include <qcsvreaderwidget.h>
#include <qdataportinterface.h>
#include <mavlink.h>

class QGpioCsvReader : public QDataPortInterface
{
public:
    QGpioCsvReader(QWidget *parent = 0);

    mavlink_gpio_t getGpioPacket();
    virtual QVariant getPacket();
    virtual QWidget* getWidget();

    virtual bool enabled();
    virtual void reset();

    virtual void saveState(QString group);
    virtual void restoreState(QString group);

private:
    QCsvReaderWidget* _csv_reader;

};

#endif // QGPIOFILEPORT_H
