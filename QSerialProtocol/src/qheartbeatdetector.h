#ifndef QHEARTBEATDETECTOR_H
#define QHEARTBEATDETECTOR_H

#include <qdatanode.h>
#include <QTimer>
#include <QDebug>

class QHeartbeatDetector : public QDataNode
{
    Q_OBJECT

private:
    QTimer _timer;

public:
    QHeartbeatDetector();

public slots:
    void receive(heartbeat_t heartbeat);
    void timeout();

signals:
    void alive(heartbeat_t heartbeat);
    void dead();
};

#endif // QHEARTBEATDETECTOR_H
