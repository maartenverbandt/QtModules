#ifndef QRUNNINGPOLARPLOTTESTER_H
#define QRUNNINGPOLARPLOTTESTER_H

#include <QObject>
#include <QTime>
#include <QPointF>
#include <QDebug>

class QRunningPolarPlotTester : public QObject
{
    Q_OBJECT
public:
    explicit QRunningPolarPlotTester(QObject *parent = 0);

protected:
    void timerEvent(QTimerEvent *e);

signals:
    void emitPoint(QPointF p);

public slots:
};

#endif // QRUNNINGPOLARPLOTTESTER_H
