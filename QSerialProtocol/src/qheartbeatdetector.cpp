#include "qheartbeatdetector.h"

QHeartbeatDetector::QHeartbeatDetector()
{
    _timer.setSingleShot(true);
    _timer.setInterval(3000);
    QObject::connect(&_timer, SIGNAL(timeout()), this, SLOT(timeout()));
}

void QHeartbeatDetector::receive(heartbeat_t heartbeat)
{
    _timer.stop();
    emit alive(heartbeat);
}

void QHeartbeatDetector::timeout()
{
    emit dead();
}
