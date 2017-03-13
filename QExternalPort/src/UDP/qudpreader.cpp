#include "qudpreader.h"

QUdpReader::QUdpReader(const int line_size, QObject *parent) :
    _socket(new QUdpSocket(parent)),
    _line_size(line_size),
    _lines_read(0)
{
    _socket->bind();
}

void QUdpReader::setPort(quint16 port)
{
    _socket->bind(port);
}

quint16 QUdpReader::getPort()
{
    return _socket->localPort();
}

QUdpSocket *QUdpReader::getSocket()
{
    return _socket;
}

void QUdpReader::reset()
{
    quint16 port = _socket->localPort();
    _socket->disconnectFromHost();
    _socket->bind(port);
    _lines_read = 0;
}

QByteArray QUdpReader::readLine()
{
    QByteArray bytes = QByteArray(_line_size,0);
    int t_lines_read = 0;
    while(_socket->hasPendingDatagrams()){
        _socket->readDatagram(bytes.data(),bytes.size());
        t_lines_read++;
    }

    if(t_lines_read > 1){
        qDebug() << "More than one message received. Try increasing the read-frequency.";
    }

    _lines_read++;
    return bytes;
}

quint64 QUdpReader::linesRead()
{
    return _lines_read;
}
