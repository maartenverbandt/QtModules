#ifndef QPOSITIONCMDPORTDIALOG_H
#define QPOSITIONCMDPORTDIALOG_H

#include <qexternalportdialog.h>
#include <qpositioncmdfileport.h>
#include <mavlink/robot_messages/mavlink.h>

class QPositionCmdPortDialog : public QExternalPortDialog
{
    Q_OBJECT

public:
    explicit QPositionCmdPortDialog(QWidget *parent = 0);

    mavlink_position_cmd_t getPositionCmdPacket();

protected:
    void timerEvent(QTimerEvent *);

private:
    QPositionCmdFilePort* _file_port;

signals:
    void positionCmdPacket(mavlink_position_cmd_t position_cmd);

};

#endif // QPOSITIONCMDPORTDIALOG_H
