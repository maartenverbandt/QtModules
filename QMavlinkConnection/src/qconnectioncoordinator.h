#ifndef QCONNECTIONCOORDINATOR_H
#define QCONNECTIONCOORDINATOR_H

#include <QObject>
#include <QList>

#include <QtSerialPort>
#include <QSerialPortInfo>
#include "qusbdevicediscoveryagent.h"

#include <QBluetoothDeviceDiscoveryAgent>
#include <QBluetoothLocalDevice>
#include <QBluetoothServiceInfo>
#include <QBluetoothSocket>

//#include <qudpdevicediscoveryagent.h>

#include <qmavlinkconnection.h>

class QMavlinkConnection;

class QConnectionCoordinator : public QObject
{
    Q_OBJECT
public:
    explicit QConnectionCoordinator(QObject *parent = 0);
    ~QConnectionCoordinator();

    //bool addMavlinkConnection();
    //bool removeMavlinkConnection();
    QMavlinkConnection* findMavlinkConnection(QString name);

    void connected(QMavlinkConnection* connection);
    void timedOut(QMavlinkConnection* connection);

    void setupUSB();
    void setupBT();
    void setupTCP();

    void scanUSB();
    void scanBT();
    void scanUDP();

private:
    QUSBDeviceDiscoveryAgent        *_discovery_agent_USB;
    QBluetoothDeviceDiscoveryAgent  *_discovery_agent_BT;
    QBluetoothLocalDevice           *_local_device_BT;

    QList<QMavlinkConnection*>      _connections;

//    void handleMavlinkConnection(QIODevice* connection, QString port_name, serial_t type);

signals:
    void mavlinkConnectionFound(QMavlinkConnection *mavlink_connection);

public slots:
    void query();

    void mavlinkConnectionUSB(QSerialPortInfo info);
    void mavlinkConnectionBT(QBluetoothDeviceInfo info);
    void mavlinkConnectionUDP(QString server, int port);

};

#endif // QCONNECTIONCOORDINATOR_H
