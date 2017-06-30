#ifndef QUDPWRITER_H
#define QUDPWRITER_H

#include <QObject>
#include <QUdpSocket>

class QUdpWriter : public QObject
{
    Q_OBJECT

public:
    QUdpWriter(QObject *parent = 0);

    quint16 getPort();
    QUdpSocket* getSocket();
    void reset();

    void writeLine(QByteArray bytes);
    quint64 linesWritten();

private:
    QUdpSocket* _socket;
    quint16 _port;
    quint64 _lines_written;

public slots:
    void setPort(quint16 port);

};

#endif // QUDPWRITER_H
