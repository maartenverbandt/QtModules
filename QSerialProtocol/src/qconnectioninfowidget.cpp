#include "qconnectioninfowidget.h"

QConnectionInfoWidget::QConnectionInfoWidget(QWidget *parent) :
    QWidget(parent),
    _timer()
{
    setup();

    _bars_rate = new QCPBars(_plot->xAxis, _plot->yAxis);
    _bars_rate->setWidth(BAR_WIDTH);
    //ui->barPlot-> addPlottable(_bars_rate);

    _bars_count = new QCPBars(_plot->xAxis, _plot->yAxis2);
    _bars_count->setWidth(BAR_WIDTH);
    //ui->barPlot->addPlottable(_bars_count);

    //ui->barPlot->xAxis->setAutoTicks(false);
    //ui->barPlot->xAxis->setAutoTickLabels(false);

    _bars_count->setBrush(QBrush(QColor(124, 252, 0, 100)));
    _bars_count->setPen(QPen(QColor(30, 130, 30), 1.0));
    _plot->yAxis->setRange(0,200);
    _plot->yAxis2->setVisible(true);

    this->reset();
}

QSize QConnectionInfoWidget::sizeHint() const
{
    return QSize(250,400);
}

void QConnectionInfoWidget::setup()
{
    _plot = new QCustomPlot(this);
    QPushButton *b = new QPushButton("reset");
    QObject::connect(b,&QPushButton::clicked, this, &QConnectionInfoWidget::reset);

    QHBoxLayout *hlayout = new QHBoxLayout();
    hlayout->addSpacerItem(new QSpacerItem(20,6,QSizePolicy::MinimumExpanding));
    hlayout->addWidget(b);

    QVBoxLayout *vlayout = new QVBoxLayout(this);
    vlayout->addWidget(_plot, 1);
    vlayout->addLayout(hlayout, 0);
}

void QConnectionInfoWidget::addMsgID(int msgid)
{
    int k = 0;
    while((k<_sort_id.length())&&((_message_id[_sort_id[k]]) <= msgid)){
        k++;
    }
    _sort_id.insert(k,_sort_id.length());
    _message_id.append(msgid);
    _message_counter.append(1);
}

void QConnectionInfoWidget::updateAxis()
{
    _tick_pos.resize(_message_id.length());
    _tick_label.resize(_message_id.length());
    _bar_pos.resize(_message_id.length());

    for(int k=0;k<_message_id.length();k++){
        _tick_pos.replace(k,k);
        _tick_label.replace(k, QString("%1").arg(_message_id[_sort_id[k]]));
        _bar_pos.replace(k,k);
    }

    //ui->barPlot->xAxis->ticker()->setTickCount(_message_id.length()); //  setTickVector (_tick_pos);
    //ui->barPlot->xAxis->setTickVectorLabels(_tick_label);
    _plot->xAxis->setRange(-0.5, _message_id.length()-0.5);
}

void QConnectionInfoWidget::updateData()
{
    double rate;

    _bar_rate_val.resize(_message_id.length());
    _bar_count_val.resize(_message_id.length());

    for(int k=0;k<_message_id.length();k++){
        rate = 1000.0*_message_counter[_sort_id[k]]/_timer.elapsed();
        if(rate>RATE_THRESHOLD){
            _bar_rate_val.replace(k,rate);
            _bar_count_val.replace(k,0);
        }
        else{
            _bar_rate_val.replace(k,0);
            _bar_count_val.replace(k,_message_counter[_sort_id[k]]);
        }
    }

    _bars_rate->setData(_bar_pos, _bar_rate_val);
    _bars_count->setData(_bar_pos, _bar_count_val);
    _plot->yAxis2->rescale();

    _plot->replot();
}

void QConnectionInfoWidget::msgReceived(int id)
{
    _msg_received++;
    int k = _message_id.indexOf(id);
    if(k>=0){
        //qDebug() << "Message found, added to counting vector.";
        _message_counter[k]++;
    }
    else{
        addMsgID(id);
        updateAxis();
    }

    if(_msg_received > REFRESH_COUNT){
        _msg_received = 0;
        updateData();
    }
}

void QConnectionInfoWidget::reset()
{
    _timer.restart();

    _message_counter.clear();
    _message_id.clear();
    _sort_id.clear();

    _msg_received = 0;
}
