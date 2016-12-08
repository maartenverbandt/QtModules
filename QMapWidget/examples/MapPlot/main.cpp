#include <QApplication>
#include <qmapwidget.h>
#include <qmapwidgettester.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QMapWidget* p = new QMapWidget();
    QMapWidgetTester *t = new QMapWidgetTester();

    QObject::connect(t,SIGNAL(orientationChanged(double)),p,SLOT(setOrientation(double)));
    QObject::connect(t,SIGNAL(poseChanged(QVector2D)),p,SLOT(setPosition(QVector2D)));
    QObject::connect(t,SIGNAL(speedChanged(QVector2D)),p,SLOT(setGlobalVelocity(QVector2D)));

    p->show();
    p->setRange(5.0);
    p->setSize(0.5);

    //p->setSize(1);

    p->addPoint(QPointF(-4.0,-4.0));
    p->addPoint(QPointF(4.0,4.0));
    p->addPoint(QPointF(-4.0,4.0));
    p->addPoint(QPointF(4.0,-4.0));

    //p->update();

    return a.exec();
}
