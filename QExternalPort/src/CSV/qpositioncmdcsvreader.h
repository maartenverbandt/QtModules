#ifndef QPOSITIONCMDFILEPORT_H
#define QPOSITIONCMDFILEPORT_H

#include <qcsvreaderdatanodewidget.h>

class QPositionCmdCsvReader : public QCsvReaderDataNodeWidget
{
    Q_OBJECT
public:
    QPositionCmdCsvReader(QWidget *parent = 0);
    virtual void transmit_packet();

};

#endif // QPOSITIONCMDFILEPORT_H
