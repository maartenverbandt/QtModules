#ifndef QMAVLINKCONNECTION_H
#define QMAVLINKCONNECTION_H

#include <QObject>
#include <QIODevice>
#include <QTimer>
#include <QMessageBox>
#include <QFileDialog>
#include <QMenu>
#include <QAction>
#include <mavlink.h>
#include <qmavlinkconnectioninfodialog.h>
#include <qmavlinkconnectionlogger.h>

#include <QDebug>

typedef enum serial_t{
    SERIAL_USB,
    SERIAL_UDP,
    SERIAL_BT
} serial_t;

class QMavlinkConnection : public QObject
{
    Q_OBJECT
public:
    explicit QMavlinkConnection(QObject *parent = 0, QIODevice *io = 0, QString name = 0, serial_t serial_type = SERIAL_USB);
    ~QMavlinkConnection();

    QString name();
    serial_t type();
    mavlink_message_t msg();
    unsigned long packetCount();
    unsigned long packetDrops();

    void mavlinkParseData(QByteArray* data);

    QAction *getDisconnectAction();
    QAction *getReconnectAction();
    QAction *getInfoAction();
    QAction *getQuicklogAction();
    QAction *getLogAction();

    QMenu *constructMenu(const QString menu_title, QWidget *parent=0);

private:
    QIODevice*          _io;
    const serial_t      _serial_type;
    const QString       _name;
    mavlink_message_t   _msg;
    mavlink_status_t    _status;

    unsigned long       _packet_count;
    unsigned long       _packet_drops;

    QTimer              _timer;
    unsigned long       _timer_packet_count;

    //actions
    QAction _disconnect_action;
    QAction _reconnect_action;
    QAction _info_action;
    QAction _log_action;
    QAction _quicklog_action;

    //methods
    void logCallback(bool checked, bool autoname=false);

signals:
    void mavlinkConnected(bool c);
    void mavlinkMsgReceived(mavlink_message_t msg);
    void closeLog();

public slots:
    void mavlinkMsgSend(mavlink_message_t msg);
    void mavlinkParseData();
    void checkTimeout();
    void checkConnection();
    void connectionInfoDialog();
    void logActionCallback(bool checked);
    void quicklogActionCallback(bool checked);
};

#endif // QMAVLINKCONNECTION_H
