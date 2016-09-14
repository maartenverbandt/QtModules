#include <QApplication>
#include <qpolarplot.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QPolarPlot* p = new QPolarPlot();
    p->show();

    p->setRange(10.0);
    p->addCircle(8.0);
    p->addCircle(4.0);

    p->setSize(4);
    p->addPoint(QPointF(-6.0,-6.0));
    p->addPoint(QPointF(6.0,6.0));
    p->addPoint(QPointF(-6.0,6.0));
    p->addPoint(QPointF(6.0,-6.0));

    //p->update();

    return a.exec();
}
