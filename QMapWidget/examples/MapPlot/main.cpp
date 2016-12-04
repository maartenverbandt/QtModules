#include <QApplication>
#include <qmapwidget.h>
#include <qmapwidgettester.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QMapWidget* p = new QMapWidget();
    QMapWidgetTester *t = new QMapWidgetTester();

    QObject::connect(t,SIGNAL(orientationChanged(double)),p,SLOT(setOrientation(double)));

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
