#include "qpositioncmdcsvreader.h"

QPositionCmdCsvReader::QPositionCmdCsvReader(QWidget *parent):
    _csv_reader(new QCsvReaderWidget("position cmd",parent))
{

}

mavlink_position_cmd_t QPositionCmdCsvReader::getPositionCmdPacket()
{
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

QVariant QPositionCmdCsvReader::getPacket()
{
    QVariant position_cmd;
    position_cmd.setValue(getPositionCmdPacket());
    return position_cmd;
}

QWidget *QPositionCmdCsvReader::getWidget()
{
    return _csv_reader;
}

bool QPositionCmdCsvReader::enabled()
{
    return _csv_reader->enabled();
}

void QPositionCmdCsvReader::reset()
{
    _csv_reader->getCsvReader()->reset();
}

void QPositionCmdCsvReader::saveState(QString group)
{
    _csv_reader->saveState(group + "/position_cmd");
}

void QPositionCmdCsvReader::restoreState(QString group)
{
    _csv_reader->restoreState(group + "/position_cmd");
}
