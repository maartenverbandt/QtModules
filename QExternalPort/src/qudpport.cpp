#include "qudpport.h"

QUdpPort::QUdpPort(const int line_size, QObject *parent) :
    QObject(parent),
    _socket(new QUdpSocket(this)),
    _line_size(line_size)
{
    _socket->bind();
}

void QUdpPort::setPort(quint16 port)
{
    _socket->bind(port);
}

quint16 QUdpPort::getPort()
{
    return _socket->localPort();
}

QUdpSocket *QUdpPort::getSocket()
{
    return _socket;
}

void QUdpPort::reset()
{
    quint16 port = _socket->localPort();
    _socket->disconnectFromHost();
    _socket->bind(port);
}

QByteArray QUdpPort::readLine()
{
    QByteArray bytes = QByteArray(_line_size,0);
    while(_socket->hasPendingDatagrams()){
        _socket->readDatagram(bytes.data(),bytes.size());
        _lines_read++;
    }

    return bytes;
}

quint64 QUdpPort::linesRead()
{
    return _lines_read;
}
