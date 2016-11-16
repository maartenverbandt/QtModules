#include "qthreadingwidget.h"

QThreadingWidget::QThreadingWidget(QWidget *parent) :
    QTableWidget(0,7,parent)
{
    QStringList header;
    header << "ID" << "priority" << "<duration>" << "<latency>" << "duration" << "latency" << "executions";
    setHorizontalHeaderLabels(header);
}

bool QThreadingWidget::hasThread(int id)
{
    return (findThread(id) >= 0);
}

int QThreadingWidget::findThread(int id)
{
    for(int k = 0; k<_threads.length() ; k++){
        if(_threads[k].id() == id){
            return k;
        }
    }
    return -1;
}

void QThreadingWidget::populateRow(int row)
{
    for(int k=0; k<7 ; k++){
        setItem(row,k,new QTableWidgetItem(0));
        item(row,k)->setTextAlignment(Qt::AlignRight);
    }

    item(row,0)->setTextAlignment(Qt::AlignLeft);
    item(row,1)->setTextAlignment(Qt::AlignCenter);
}

void QThreadingWidget::updateWidget()
{
    for(int k=0;k<_threads.length();k++)
        updateWidget(k);
}

void QThreadingWidget::updateWidget(int index)
{
    // Check if new thread
    if(index>=rowCount()){
        insertRow(rowCount());
        populateRow(index);
    }
    // Fill out data
    item(index,0)->setText(QString::number(_threads[index].id()));
    item(index,1)->setText(QString::number(_threads[index].priority()));
    item(index,2)->setText(QString::number(_threads[index].averageDuration()));
    item(index,3)->setText(QString::number(_threads[index].averageLatency()));
    item(index,4)->setText(QString::number(_threads[index].duration()));
    item(index,5)->setText(QString::number(_threads[index].latency()));
    item(index,6)->setText(QString::number(_threads[index].executions()));
}

void QThreadingWidget::updateThread(Thread thread)
{
    int index = findThread(thread.id());
    if(index>=0){
        _threads[index] = thread;
    } else {
        _threads.append(thread);
        index++;
    }
    updateWidget(index);
}

