#ifndef QPOSITIONCMDFILEPORT_H
#define QPOSITIONCMDFILEPORT_H

#include <qcsvreaderwidget.h>
#include <qdataportinterface.h>
#include <mavlink.h>

class QPositionCmdCsvReader : public QDataPortInterface
{
public:
    QPositionCmdCsvReader(QWidget *parent = 0);

    mavlink_position_cmd_t getPositionCmdPacket();
    virtual QVariant getPacket();
    virtual QWidget* getWidget();

    virtual bool enabled();
    virtual void reset();

    virtual void saveState(QString group);
    virtual void restoreState(QString group);

private:
    QCsvReaderWidget* _csv_reader;

};

#endif // QPOSITIONCMDFILEPORT_H
