#ifndef TALKER_H
#define TALKER_H

#include <QObject>
#include <QDebug>
#include <mavlink.h>
#include <QTime>

class Talker : public QObject
{
    Q_OBJECT
public:
    explicit Talker(QObject *parent = 0);

private slots:
    void timerEvent(QTimerEvent *e);

signals:
    void message_sent(QList<QVariant> l);

};

#endif // TALKER_H
