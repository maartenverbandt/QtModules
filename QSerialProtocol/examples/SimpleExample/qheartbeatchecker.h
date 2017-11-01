#ifndef QHEARTBEATCHECKER_H
#define QHEARTBEATCHECKER_H

#include <qdatanodewidget.h>
#include <QLabel>

class QHeartbeatChecker : public QDataNodeWidget
{
    Q_OBJECT

public:
    explicit QHeartbeatChecker(QDataNode* datanode, QWidget *parent = 0);

private:
    QLabel *_label;

public slots:
    virtual void receive(heartbeat_t heartbeat);

};

#endif // QHEARTBEATCHECKER_H
