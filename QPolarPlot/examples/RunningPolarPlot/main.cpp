#include <QApplication>
#include <qpolarplot.h>
#include <qrunningpolarplot.h>
#include <qrunningpolarplottester.h>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QRunningPolarPlot* p = new QRunningPolarPlot(50,0);
    p->show();

    QRunningPolarPlotTester* t = new QRunningPolarPlotTester();
    QObject::connect(t,SIGNAL(emitPoint(QPointF)),p,SLOT(updatePoint(QPointF)));

    p->setRange(1.5);
    p->addCircle(0.50);
    p->addCircle(1.0);

    p->setSize(10);


    return a.exec();
}
