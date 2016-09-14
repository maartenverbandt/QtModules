#include "qrunningpolarplottester.h"

QRunningPolarPlotTester::QRunningPolarPlotTester(QObject *parent) : QObject(parent)
{
    startTimer(10);
}

void QRunningPolarPlotTester::timerEvent(QTimerEvent *e)
{
     int m = QTime::currentTime().msecsSinceStartOfDay();
     QPointF p(sin(m*0.001*2.0*M_PI*0.5),0.5*cos(m*0.001*2.0*M_PI*0.5));
     qDebug() << p << m;
     emit emitPoint(p);
}
