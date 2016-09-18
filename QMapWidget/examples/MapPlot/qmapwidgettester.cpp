#include "qmapwidgettester.h"

QMapWidgetTester::QMapWidgetTester(QObject *parent) : QObject(parent)
{
    startTimer(50);
}

void QMapWidgetTester::timerEvent(QTimerEvent *e)
{
     int m = QTime::currentTime().msecsSinceStartOfDay();
     double orientation =  1.2*sin(m*0.001*2.0*M_PI*0.2);
     emit orientationChanged(orientation);
}
