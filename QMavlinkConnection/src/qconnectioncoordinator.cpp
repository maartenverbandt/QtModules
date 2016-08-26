#include "qconnectioncoordinator.h"

QConnectionCoordinator::QConnectionCoordinator(QObject *parent) :
    QObject(parent),
    _local_device_BT(new QBluetoothLocalDevice)
{
    this->setupBT();
    this->setupUSB();
}

QConnectionCoordinator::~QConnectionCoordinator()
{

}

QMavlinkConnection *QConnectionCoordinator::findMavlinkConnection(QString name)
{
    for(int k=0;k<_connections.length();k++){
        if(_connections[k]->name() == name){
            return _connections[k];
        }
    }
    return NULL;
}

void QConnectionCoordinator::connected(QMavlinkConnection *connection)
{
    connection->setConnected();
    _connections.append(connection);
    emit mavlinkConnectionFound(connection);
    qDebug() << "Device name:" << connection->name();
    qDebug() << "mavlink detected";
}

void QConnectionCoordinator::timedout(QMavlinkConnection *connection)
{
    connection->deleteLater();
    qDebug() << "Device name:" << connection->name();
    qDebug() << "no mavlink detected";
}

void QConnectionCoordinator::query()
{
    this->scanUSB();
    this->scanBT();
}

void QConnectionCoordinator::setupUSB()
{
    qDebug() << "setting up USB";
    _discovery_agent_USB = new QUSBDeviceDiscoveryAgent();
    connect(_discovery_agent_USB, SIGNAL(deviceDiscovered(QSerialPortInfo)),
            this, SLOT(mavlinkConnectionUSB(QSerialPortInfo)));
}

void QConnectionCoordinator::setupBT()
{
    qDebug() << "setting up bluetooth";
    _discovery_agent_BT = new QBluetoothDeviceDiscoveryAgent();

    // Bluetooth adaptor configuration
    _local_device_BT->powerOn();
    _local_device_BT->setHostMode(QBluetoothLocalDevice::HostDiscoverable);
    _discovery_agent_BT->setInquiryType(QBluetoothDeviceDiscoveryAgent::GeneralUnlimitedInquiry);

    connect(_discovery_agent_BT, SIGNAL(deviceDiscovered(QBluetoothDeviceInfo)),
            this, SLOT(mavlinkConnectionBT(QBluetoothDeviceInfo)));
    //connect(discoveryAgent, SIGNAL(finished()), this, SLOT(scanFinished()));

    //connect(localDevice, SIGNAL(hostModeStateChanged(QBluetoothLocalDevice::HostMode)),
            //this, SLOT(hostModeStateChanged(QBluetoothLocalDevice::HostMode)));

    //hostModeStateChanged(localDevice->hostMode());
}

void QConnectionCoordinator::scanUSB()
{
    _discovery_agent_USB->start();
}

void QConnectionCoordinator::scanBT()
{
    _discovery_agent_BT->start();
}

void QConnectionCoordinator::scanUDP()
{
    //_discovery_agent_TCP->start();
}

/*void QConnectionCoordinator::handleMavlinkConnection(QIODevice *connection, QString port_name, serial_t type)
{
    QMavlinkConnection *mavlink_connection = new QMavlinkConnection(this,connection, port_name, type);
    QObject::connect(mavlink_connection, SIGNAL(mavlinkConnected(bool)), this, SLOT(mavlinkConnected(bool)));
    if(type == SERIAL_BT)
        QObject::connect(connection, SIGNAL(connected()), mavlink_connection, SLOT(checkConnection()));
}*/

void QConnectionCoordinator::mavlinkConnectionUSB(QSerialPortInfo info)
{
    QSerialPort *io_device = new QSerialPort(info);
    io_device->setBaudRate(QSerialPort::Baud115200);
    if(!io_device->open(QIODevice::ReadWrite)){
        qDebug() << "Error opening port" << io_device->portName();
    }

    QMavlinkConnection *connection = new QMavlinkConnection(this,io_device,io_device->portName(),QMavlinkConnection::SERIAL_USB);
    connection->setPending();
}

void QConnectionCoordinator::mavlinkConnectionBT(QBluetoothDeviceInfo info)
{
    QBluetoothSocket *io_device = new QBluetoothSocket(QBluetoothServiceInfo::RfcommProtocol);
    qDebug() << "Created bluetooth socket";
    io_device->connectToService(info.address(),QBluetoothUuid(QBluetoothUuid::SerialPort));
    qDebug() << "ConnectToBluetoothService done";

    QMavlinkConnection *connection = new QMavlinkConnection(this,io_device,info.name(),QMavlinkConnection::SERIAL_BT);
    connection->setPending();
}

void QConnectionCoordinator::mavlinkConnectionUDP(QString server, int port)
{
    /*QTcpSocket* socket = new QTcpSocket;
    socket->connectToHost(server, port);

    if(socket->waitForConnected(30000)){
        this->handleMavlinkConnection(socket, server, SERIAL_TCP);
    } else {
        qDebug() << "Error when connecting to host " + server + ":" + QString::number(port);
        qDebug() << socket->errorString();
    }*/

}
