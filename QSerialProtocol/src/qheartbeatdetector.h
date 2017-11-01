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
    QDataNode *_datanode;

public:
    explicit QHeartbeatDetector(QDataNode *datanode);

public slots:
    void receive(heartbeat_t heartbeat);
    void timeout();
    void start();

signals:
    void alive(QDataNode *datanode);
    void dead(QDataNode *datanode);
};

#endif // QHEARTBEATDETECTOR_H
