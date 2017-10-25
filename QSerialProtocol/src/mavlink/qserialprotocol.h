#ifndef SERIAL_PROTOCOL_H
#define SERIAL_PROTOCOL_H

#include <QIODevice>
#include <QDebug>
#include <qdatanode.h>

class QSerialProtocol : public QDataNode {
    Q_OBJECT

private:
    mavlink_message_t _msg;
    mavlink_status_t _status;
    int _packet_count;
    int _packet_drops;

    QIODevice* _io;

public:
    QSerialProtocol(QIODevice *io, QObject *parent = 0);

    int packetCount();
    int packetDrops();

private slots:
    void decode();
    void encode(mavlink_message_t msg);

public slots:
    void receive(heartbeat_t heartbeat);
    void receive(event_t event);
    void receive(param_int_t param_int);
    void receive(param_float_t param_float);

};

#endif // SERIAL_PROTOCOL_H
