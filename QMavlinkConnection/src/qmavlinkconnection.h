#ifndef QMAVLINKCONNECTION_H
#define QMAVLINKCONNECTION_H

#include <QObject>
#include <QIODevice>
#include <QTimer>
#include <QMessageBox>
#include <QFileDialog>
#include <QMenu>
#include <QAction>
#include <qconnectioncoordinator.h>
#include <mavlink.h>
#include <qmavlinkconnectioninfodialog.h>
#include <qmavlinkconnectionlogger.h>

#include <QDebug>

class QConnectionCoorindator;

class QMavlinkConnection : public QObject
{
    Q_OBJECT
public:
    typedef enum serial_t{
        SERIAL_USB,
        SERIAL_UDP,
        SERIAL_BT
    } serial_t;

    explicit QMavlinkConnection(QObject *parent, QIODevice *io = 0, QString name = 0, serial_t serial_type = SERIAL_USB);
    ~QMavlinkConnection();

    QString name();
    serial_t type();
    mavlink_message_t msg();
    unsigned long packetCount();
    unsigned long packetDrops();

    unsigned int getRobotID();
    unsigned int getRobotType();
    QString getMenuName();

    void setPending();
    void setConnected();

    QAction *getDisconnectAction();
    QAction *getReconnectAction();
    QAction *getInfoAction();
    QAction *getQuicklogAction();
    QAction *getLogAction();

    QMenu *constructMenu(const QString menu_title, QWidget *parent = 0);
    QMenu *constructMenu(QWidget *parent = 0);

private:
    QIODevice*          _io;
    const serial_t      _serial_type;
    const QString       _name;
    mavlink_message_t   _msg;
    mavlink_status_t    _status;

    unsigned int        _robot_id;
    unsigned int        _robot_type;

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
    void mavlinkMsgReceived(mavlink_message_t msg);
    void closeLog();

public slots:
    // message handling
    void checkHeartbeat(mavlink_message_t msg);
    void timeout();
    void mavlinkParseData();
    void mavlinkMsgSend(mavlink_message_t msg);

    // action callbacks
    void connectionInfoDialog();
    void logActionCallback(bool checked);
    void quicklogActionCallback(bool checked);
};

#endif // QMAVLINKCONNECTION_H
