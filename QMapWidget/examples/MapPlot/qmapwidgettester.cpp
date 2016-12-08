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

     double x = 2.0*sin(m*0.001*2.0*M_PI*0.2);
     double y = 2.5*cos(m*0.001*2.0*M_PI*0.3);
     emit poseChanged(QVector2D(x,y));

     double vx = 2.0*cos(m*0.001*2.0*M_PI*0.2)*2.0*M_PI*0.2;
     double vy = -2.5*sin(m*0.001*2.0*M_PI*0.3)*2.0*M_PI*0.3;
     emit speedChanged(QVector2D(vx,vy)*0.1);
}
