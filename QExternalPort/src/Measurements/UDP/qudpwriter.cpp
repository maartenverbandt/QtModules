#include "qudpwriter.h"

quint16 QUdpWriter::_next_port = 28000;

QUdpWriter::QUdpWriter(QObject *parent) :
    QObject(parent),
    _socket(new QUdpSocket(parent)),
    _lines_written(0)
{
    _port = _next_port;
    _next_port++;
}

void QUdpWriter::setPort(quint16 port)
{
    _port = port;
}

quint16 QUdpWriter::getPort()
{
    return _port;
}

QUdpSocket *QUdpWriter::getSocket()
{
    return _socket;
}

void QUdpWriter::reset()
{
    setPort(_port);
    _lines_written = 0;
}

void QUdpWriter::writeLine(QByteArray bytes)
{
    _socket->writeDatagram(bytes,QHostAddress::LocalHost,getPort());
    _lines_written++;
}

quint64 QUdpWriter::linesWritten()
{
    return _lines_written;
}
