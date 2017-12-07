#ifndef QPOSITIONCMDCSVCOMMAND_H
#define QPOSITIONCMDCSVCOMMAND_H

#include <qcsvcommanddatanodewidget.h>

class QPositionCmdCsvReader : public QCsvReaderDataNodeWidget
{
    Q_OBJECT
public:
    QPositionCmdCsvReader(QWidget *parent = 0);
    virtual void transmit_packet();

};

#endif // QPOSITIONCMDCSVCOMMAND_H
