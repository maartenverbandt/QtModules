#include "qpositioncmdfileport.h"

QPositionCmdFilePort::QPositionCmdFilePort(QObject *parent):
    QObject(parent),
    _csv_reader(new QCsvReaderWidget(0))
{

}

mavlink_position_cmd_t QPositionCmdFilePort::getPositionCmdPacket()
{
    int k = 0;
    mavlink_position_cmd_t position_cmd;

    QList<double> values = _csv_reader->readLine();
    while(values.length() < 6)
        values.append(0.0);

    QListIterator<double> i(values);
    position_cmd.x = i.next();
    position_cmd.y = i.next();
    position_cmd.z = i.next();
    position_cmd.xFF = i.next();
    position_cmd.yFF = i.next();
    position_cmd.zFF = i.next();

    return position_cmd;
}

QVariant QPositionCmdFilePort::getPacket()
{
    QVariant position_cmd;
    position_cmd.setValue(getPositionCmdPacket());
    return position_cmd;
}

QWidget *QPositionCmdFilePort::getWidget()
{
    return _csv_reader;
}


