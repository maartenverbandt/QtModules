#include "qthreadingwidget.h"

QThreadingWidget::QThreadingWidget(QWidget *parent) :
    QTableWidget(0,7,parent),
    _popup(new QAction("Thread info", this))
{
    QStringList header;
    header << "ID" << "priority" << "<duration>" << "<latency>" << "duration" << "latency" << "executions";
    setHorizontalHeaderLabels(header);

    QObject::connect(_popup,SIGNAL(triggered()),this,SLOT(show()));
}

QThreadingWidget::~QThreadingWidget()
{
    //delete ui;
}

bool QThreadingWidget::hasThread(int id)
{
    return (findThread(id) >= 0);
}

int QThreadingWidget::findThread(int id)
{
    for(int k = 0; k<threads.length() ; k++){
        if(threads[k].id == id){
            return k;
        }
    }
    return -1;
}

QAction *QThreadingWidget::getPopupAction()
{
    return _popup;
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

void QThreadingWidget::updateThreadInfo(thread_t thread)
{
    int index = findThread(thread.id);
    if(index>=0){
        threads[index] = thread;
    } else {
        threads.append(thread);
        insertRow(rowCount());
        index=rowCount()-1;
        populateRow(index);
    }

    item(index,0)->setText(QString::number(thread.id));
    item(index,1)->setText(QString::number(thread.priority));
    item(index,2)->setText(QString::number(thread.duration/thread.executions));
    item(index,3)->setText(QString::number(thread.latency/thread.executions));
    item(index,4)->setText(QString::number(thread.duration));
    item(index,5)->setText(QString::number(thread.latency));
    item(index,6)->setText(QString::number(thread.executions));
}

void QThreadingWidget::closeEvent(QCloseEvent *e)
{
    setVisible(false);
}
