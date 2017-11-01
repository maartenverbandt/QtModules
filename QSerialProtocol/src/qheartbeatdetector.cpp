#include "qheartbeatdetector.h"

QHeartbeatDetector::QHeartbeatDetector(QDataNode *datanode) :
    _datanode(datanode)
{
    connectTo(_datanode);

    _timer.setSingleShot(true);
    _timer.setInterval(3000);
    QObject::connect(&_timer, SIGNAL(timeout()), this, SLOT(timeout()));
}

void QHeartbeatDetector::receive(heartbeat_t)
{
    _timer.stop();
    emit alive(_datanode);
    deleteLater();
}

void QHeartbeatDetector::timeout()
{
    emit dead(_datanode);
    deleteLater();
}

void QHeartbeatDetector::start()
{
    _timer.start();
}
