#include "qmavlinkconnectionlogger.h"

QMavlinkConnectionLogger::QMavlinkConnectionLogger(const QString filename, QObject *parent, bool openfile) :
    QObject(parent)
{
    if(openfile)
        this->startLogging(filename);
}

QMavlinkConnectionLogger::~QMavlinkConnectionLogger()
{
    this->stopLogging();
}

bool QMavlinkConnectionLogger::startLogging(const QString fileName)
{
    // open log file
    _log.setFileName(fileName);
    return _log.open(QIODevice::WriteOnly);
}

int QMavlinkConnectionLogger::addLine(const QString line)
{
    QString line_ = line + QString("\n");
    return _log.write(line_.toLocal8Bit());
}

void QMavlinkConnectionLogger::stopLogging()
{
    // close file
    _log.close();
}

void QMavlinkConnectionLogger::mavlinkMsgReceived(mavlink_message_t msg)
{
    /*if((msg.msgid>=100)&&(msg.msgid<110)){
        QString line;
        switch(msg.msgid){
            case MAVLINK_MSG_ID_MOTOR_LOG:{
                mavlink_motor_log_t motor_log;
                mavlink_msg_motor_log_decode(&msg, &motor_log);

                line = QString::number(MAVLINK_MSG_ID_BALLBOT_LOG) + "\t" +
                       QString::number(motor_log.time) + "\t" +
                       QString::number(motor_log.position) + "\t" +
                       QString::number(motor_log.voltage) + "\t" +
                       QString::number(motor_log.current);
                break;
            }

            case MAVLINK_MSG_ID_BALLBOT_LOG:{
                mavlink_ballbot_log_t ballbot_log;
                mavlink_msg_ballbot_log_decode(&msg, &ballbot_log);

                line = QString::number(MAVLINK_MSG_ID_BALLBOT_LOG) + "\t" +
                       QString::number(ballbot_log.time) + "\t" +
                       QString::number(ballbot_log.Vmot0) + "\t" +
                       QString::number(ballbot_log.Vmot1) + "\t" +
                       QString::number(ballbot_log.Vmot2) + "\t" +
                       QString::number(ballbot_log.roll) + "\t" +
                       QString::number(ballbot_log.pitch) + "\t" +
                       QString::number(ballbot_log.yaw) + "\t" +
                       QString::number(ballbot_log.rollcmd) + "\t" +
                       QString::number(ballbot_log.pitchcmd) + "\t" +
                       QString::number(ballbot_log.yawcmd) + "\t" +
                       QString::number(ballbot_log.Imot0) + "\t" +
                       QString::number(ballbot_log.Imot1) + "\t" +
                       QString::number(ballbot_log.Imot2) + "\t" +
                       QString::number(ballbot_log.Encmot0) + "\t" +
                       QString::number(ballbot_log.Encmot1) + "\t" +
                       QString::number(ballbot_log.Encmot2);
                break;
            }
        }

        this->addLine(line);
    }*/
}

