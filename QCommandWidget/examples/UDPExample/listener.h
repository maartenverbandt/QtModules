#ifndef LISTENER_H
#define LISTENER_H

#include <qdatanode.h>
#include <QDebug>

class Listener : public QDataNode
{
    Q_OBJECT
public:
    explicit Listener(QObject *parent = 0);

public slots:
    virtual void receive(gpio_t);
    virtual void receive(velocity_cmd_t);
    virtual void receive(position_cmd_t);

};

#endif // LISTENER_H
