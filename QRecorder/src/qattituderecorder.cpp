#include "qattituderecorder.h"

QAttitudeRecorder::QAttitudeRecorder(QObject *parent) :
    QAbstractRecorder("Attitude",parent)
{
    //do nothing
}

QString QAttitudeRecorder::insertHeader()
{
    QString insert;

    // Excitation
    insert += "\t<excitation>\n";
    insert += "\t\t<type>unknown</type>\n";
    insert += "\t\t<fmin>0</fmin>\n";
    insert += "\t\t<fmax>inf</fmax>\n";
    insert += "\t\t<fs>0</fs>\n";
    insert += "\t\t<period>inf</period>\n";
    insert += "\t</excitation>\n";

    // Labels
    insert += "\t<labels>\n";
    insert += "\t\t<value>time</value>\n";
    insert += "\t\t<value>roll</value>\n";
    insert += "\t\t<value>pitch</value>\n";
    insert += "\t\t<value>yaw</value>\n";
    insert += "\t\t<value>rollcmd</value>\n";
    insert += "\t\t<value>pitchcmd</value>\n";
    insert += "\t\t<value>yawcmd</value>\n";
    insert += "\t\t<value>rollact</value>\n";
    insert += "\t\t<value>pitchact</value>\n";
    insert += "\t\t<value>yawact</value>\n";
    insert += "\t\t<value>rollcont</value>\n";
    insert += "\t\t<value>pitchcont</value>\n";
    insert += "\t\t<value>yawcont</value>\n";
    insert += "\t</labels>";

    return insert;
}

void QAttitudeRecorder::receive(attitude_t attitude)
{
    if (isRecording()) {
        QString line = "\t\t<row>";
        line += QString::number(attitude.time);
        line += "\t" + QString::number(attitude.roll);
        line += "\t" + QString::number(attitude.pitch);
        line += "\t" + QString::number(attitude.yaw);
        line += "\t" + QString::number(attitude.roll_cmd);
        line += "\t" + QString::number(attitude.pitch_cmd);
        line += "\t" + QString::number(attitude.yaw_cmd);
        line += "\t" + QString::number(attitude.roll_act);
        line += "\t" + QString::number(attitude.pitch_act);
        line += "\t" + QString::number(attitude.yaw_act);
        line += "\t" + QString::number(attitude.roll_cont);
        line += "\t" + QString::number(attitude.pitch_cont);
        line += "\t" + QString::number(attitude.yaw_cont);
        line += "</row>\n";

        _log->write(line.toLocal8Bit());
    }
}
