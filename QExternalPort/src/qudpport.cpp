#include "qudpport.h"

QUdpPort::QUdpPort(QObject *parent) :
    QObject(parent),
    _socket(new QUdpSocket(this)),
    _line_size(line_size)
{
    _socket->bind(); //bind to random port
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
    _socket->readAll();
}

QByteArray QUdpPort::readLine()
{
    QByteArray bytes;
    while(_socket->bytesAvailable()>=_line_size){
        bytes = _socket->read(_line_size);
        _lines_read++;
    }
    return bytes;
}

quint64 QUdpPort::linesRead()
{
    return _lines_read;
}
