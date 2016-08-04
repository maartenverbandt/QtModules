#ifndef QRUNNINGPLOT_H
#define QRUNNINGPLOT_H

#include "qcustomplot.h"
#include <QVector>
#include <QWidget>
#include <QMenu>

#define QRUNNINGPLOT_TYPE_GRAPH 0
#define QRUNNINGPLOT_TYPE_CURVE 1

class QRunningPlot : public QCustomPlot
{
    Q_OBJECT

public:
    explicit QRunningPlot(QWidget *parent = 0);
    void init(double span, uint8_t n, uint8_t type = QRUNNINGPLOT_TYPE_GRAPH);
    void addDataPoint(double x, double y, uint8_t g, double t = 0.0);
    void reDraw();
    void setAxes(QCPAxis *keyAxis, QCPAxis *valueAxis, uint8_t g);

protected:
    void contextMenuEvent(QContextMenuEvent *event);

private:
    uint8_t _type;
    double _span;

private slots:
    void setSpanInput();

};

/*class QSetSpanAction: public QAction
{
    Q_OBJECT

public:
    explicit QSetSpanAction(const QString &text, QWidget *parent = 0, QRunningPlot *plot = this);

private:

}; */

#endif // QRUNNINGPLOT_H
