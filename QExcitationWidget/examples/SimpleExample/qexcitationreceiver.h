#ifndef QEXCITATIONRECEIVER_H
#define QEXCITATIONRECEIVER_H

#include <qdatanode.h>
#include <QDebug>

class QExcitationReceiver : public QDataNode
{
    Q_OBJECT
public:
    explicit QExcitationReceiver(QObject *parent = 0);

public slots:
    virtual void receive(signal_multisine_t);
    virtual void receive(signal_sweptsine_t);
    virtual void receive(event_t);

};

#endif // QEXCITATIONRECEIVER_H
