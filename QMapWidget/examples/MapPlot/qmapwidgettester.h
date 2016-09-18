#ifndef QMAPWIDGETTESTER_H
#define QMAPWIDGETTESTER_H

#include <QObject>
#include <QTime>

class QMapWidgetTester : public QObject
{
    Q_OBJECT
public:
    explicit QMapWidgetTester(QObject *parent = 0);

private:
    void timerEvent(QTimerEvent *e);

signals:
    void orientationChanged(double orientation);

};

#endif // QMAPWIDGETTESTER_H
