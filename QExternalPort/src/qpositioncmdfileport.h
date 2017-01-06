#ifndef QPOSITIONCMDFILEPORT_H
#define QPOSITIONCMDFILEPORT_H

#include <qcsvreaderwidget.h>
#include <qpositioncmdportinterface.h>

class QPositionCmdFilePort : public QObject, public QPositionCmdPortInterface
{
    Q_OBJECT

public:
    QPositionCmdFilePort(QObject *parent = 0);

    mavlink_position_cmd_t getPositionCmdPacket();
    QVariant getPacket();
    QWidget* getWidget();

private:
    QCsvReaderWidget* _csv_reader;

};

#endif // QPOSITIONCMDFILEPORT_H
