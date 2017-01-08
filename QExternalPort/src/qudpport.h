#ifndef QUDPPORT_H
#define QUDPPORT_H

#include <QObject>
#include <QUdpSocket>

class QUdpPort : public QObject
{
    Q_OBJECT
public:
    explicit QUdpPort(const int line_size, QObject *parent = 0);

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

#endif // QUDPPORT_H
