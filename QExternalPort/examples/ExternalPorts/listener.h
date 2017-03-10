#ifndef LISTENER_H
#define LISTENER_H

#include <QObject>
#include <QDebug>
#include <mavlink.h>

class Listener : public QObject
{
    Q_OBJECT
public:
    explicit Listener(QObject *parent = 0);

public slots:
    void message_received(QList<QVariant> l);

};

#endif // LISTENER_H
