#ifndef QDATANODE_H
#define QDATANODE_H

#include <QObject>
#include <QVariant>
#include <qserialprotocol.h>

class QDataNode : public QObject
{
    Q_OBJECT

public:
    explicit QDataNode(QObject *parent = 0);

signals:
    void readyRead();

protected slots:
    virtual void transmit(mavlink_heartbeat_t){}
    virtual void transmit(mavlink_event_t){}
    virtual void transmit(mavlink_param_int_t){}
    virtual void transmit(mavlink_param_float_t){}
    virtual void transmit(mavlink_param_string_t){}
    virtual void transmit(mavlink_param_data_t){}

    virtual void receive(mavlink_heartbeat_t){}
    virtual void receive(mavlink_event_t){}
    virtual void receive(mavlink_param_int_t){}
    virtual void receive(mavlink_param_float_t){}
    virtual void receive(mavlink_param_string_t){}
    virtual void receive(mavlink_param_data_t){}

};

#endif // QDATANODE_H
