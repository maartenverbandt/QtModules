#ifndef QPRINTLOG_H
#define QPRINTLOG_H

#include <qdatanode.h>
#include <QFile>
#include <QDir>
#include <qprintstitcher.h>
#include <QDebug>

class QPrintLog : public QDataNode
{
    Q_OBJECT

public:
    explicit QPrintLog(QObject *parent = 0, bool opennow = true);
    void open(QString robot);

private:
    QPrintStitcher *_stitcher = new QPrintStitcher(this);
    QFile *_log;

    void write(QString line);

public slots:
    virtual void receive(print_t);

};

#endif // QPRINTLOG_H
