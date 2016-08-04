#include "qusbdevicediscoveryagent.h"

QUSBDeviceDiscoveryAgent::QUSBDeviceDiscoveryAgent(QObject *parent) : QObject(parent)
{

}

QUSBDeviceDiscoveryAgent::~QUSBDeviceDiscoveryAgent()
{

}

void QUSBDeviceDiscoveryAgent::start()
{
    QList<QSerialPortInfo> serial_port_list = QSerialPortInfo::availablePorts();

    foreach (const QSerialPortInfo &serial_port, serial_port_list) {
        qDebug() << serial_port.portName();
        if(!(serial_port.portName().contains("ttyS"))){
            emit deviceDiscovered(serial_port);
        }
    }
}

