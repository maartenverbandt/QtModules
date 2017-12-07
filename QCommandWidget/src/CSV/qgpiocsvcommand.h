#ifndef QGPIOCSVCOMMAND_H
#define QGPIOCSVCOMMAND_H

#include <qcsvcommanddatanodewidget.h>

class QGpioCsvReader : public QCsvReaderDataNodeWidget
{
    Q_OBJECT
public:
    QGpioCsvReader(QWidget *parent = 0);
    virtual void transmit_packet();

};

#endif // QGPIOCSVCOMMAND_H
