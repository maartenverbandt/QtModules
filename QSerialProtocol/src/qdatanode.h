#ifndef QDATANODE_H
#define QDATANODE_H

#include <QObject>
#include <QVariant>
#include <qserialprotocol_typedefs.h>

class QDataNode : public QObject
{
    Q_OBJECT

public:
    explicit QDataNode(QObject *parent = 0);

    void transmitTo(QDataNode* other);
    void receiveFrom(QDataNode* other);
    static void connect(QDataNode* n1, QDataNode* n2);

signals:
    void readyRead();

    void transmit(heartbeat_t);
    void transmit(event_t);
    void transmit(param_int_t);
    void transmit(param_float_t);
    void transmit(param_string_t);
    void transmit(param_data_t);

protected slots:
    virtual void receive(heartbeat_t){}
    virtual void receive(event_t){}
    virtual void receive(param_int_t){}
    virtual void receive(param_float_t){}
    virtual void receive(param_string_t){}
    virtual void receive(param_data_t){}

};

#endif // QDATANODE_H
