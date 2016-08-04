#include "qrunningplot.h"

QRunningPlot::QRunningPlot(QWidget *parent) :
    QCustomPlot(parent)
{
}

void QRunningPlot::init(double span, uint8_t n, uint8_t type)
{
    this->_span = span;
    this->_type = type;

    QVector<double> x(100);
    QVector<double> y(100);

    for(int i=-x.size(); i<0; i++){
        x[i+x.size()] = i*0.05;
        y[i+x.size()] = 0;
    }

    for(int i=0;i<n;i++){
        switch(_type){
            case QRUNNINGPLOT_TYPE_GRAPH:
                this->addPlottable(new QCPGraph(this->xAxis,this->yAxis));
                ((QCPGraph*)(this->plottable(i)))->setData(x, y);
                break;
            case QRUNNINGPLOT_TYPE_CURVE:
                this->addPlottable(new QCPCurve(this->xAxis,this->yAxis));
                //((QCPCurve*)(this->plottable(i)))->setData(x, y, y);
                break;
            default:
                this->addPlottable(new QCPGraph(this->xAxis,this->yAxis));
                ((QCPGraph*)(this->plottable(i)))->setData(x, y);
                break;
        }
    }
}

void QRunningPlot::addDataPoint(double x, double y, uint8_t g, double t){
    switch(_type){
        case QRUNNINGPLOT_TYPE_GRAPH:
            ((QCPGraph*)(this->plottable(g)))->removeDataBefore(x-_span);
            ((QCPGraph*)(this->plottable(g)))->addData(x, y);
            break;
        case QRUNNINGPLOT_TYPE_CURVE:
            ((QCPCurve*)(this->plottable(g)))->removeDataBefore(t-_span);
            ((QCPCurve*)(this->plottable(g)))->addData(t, x, y);
            break;
        default:
            ((QCPGraph*)(this->plottable(g)))->removeDataBefore(x-_span);
            ((QCPGraph*)(this->plottable(g)))->addData(x, y);
            break;
    }
}

void QRunningPlot::reDraw()
{
    this->rescaleAxes();
    this->replot();
}

void QRunningPlot::contextMenuEvent(QContextMenuEvent *event)
{
    QMenu menu(this);
    QAction setSpanAction("Set horizon",this);
    menu.addAction(&setSpanAction);
    QObject::connect(&setSpanAction, SIGNAL(triggered()), this, SLOT(setSpanInput()));
    menu.exec(event->globalPos());
}

void QRunningPlot::setSpanInput()
{
    //this->_span = (QInputDialog::getText(0, tr("Plotting time horizon"), tr("Time horizon:"), QLineEdit::Normal, "60", 0)).toInt();
    this->_span = abs(QInputDialog::getInt(0, tr("Plotting time horizon"), tr("Time horizon:"), QLineEdit::Normal));
}

void QRunningPlot::setAxes(QCPAxis *keyAxis, QCPAxis *valueAxis, uint8_t g){
    this->plottable(g)->setKeyAxis(keyAxis);
    this->plottable(g)->setValueAxis(valueAxis);
}
