#ifndef QGPIOFILEPORT_H
#define QGPIOFILEPORT_H

#include <qcsvreaderdatanodewidget.h>

class QGpioCsvReader : public QCsvReaderDataNodeWidget
{
    Q_OBJECT
public:
    QGpioCsvReader(QWidget *parent = 0);
    virtual void transmit_packet();

};

#endif // QGPIOFILEPORT_H
