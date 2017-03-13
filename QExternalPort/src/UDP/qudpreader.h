#ifndef QUDPREADER_H
#define QUDPREADER_H

#include <QUdpSocket>

class QUdpReader{
public:
    QUdpReader(const int line_size, QObject *parent = 0);

    void setPort(quint16 port);
    quint16 getPort();
    QUdpSocket* getSocket();
    void reset();

    QByteArray readLine();
    quint64 linesRead();

private:
    QUdpSocket* _socket;
    const int _line_size;
    quint64 _lines_read;

};

#endif // QUDPREADER_H
