#ifndef QMAVLINKCONNECTIONLOGGER_H
#define QMAVLINKCONNECTIONLOGGER_H

#include <QObject>
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include <QDir>
#include <QDateTime>
#include "mavlink.h"

class QMavlinkConnectionLogger : public QObject
{
    Q_OBJECT
public:
    explicit QMavlinkConnectionLogger(const QString filename, QObject *parent = 0, bool openfile = true);
    ~QMavlinkConnectionLogger();

    bool startLogging(const QString fileName);
    int addLine(const QString line);
    void stopLogging();

private:
    QFile   _log;

signals:
    void mavlinkMsgSend(mavlink_message_t msg);

public slots:
    void mavlinkMsgReceived(mavlink_message_t msg);
};

#endif // QMAVLINKCONNECTIONLOGGER_H
