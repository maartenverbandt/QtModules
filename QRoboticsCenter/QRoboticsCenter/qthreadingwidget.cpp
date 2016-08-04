#include "qthreadingwidget.h"

QThreadingWidget::QThreadingWidget(QWidget *parent) :
    QTableWidget(0,7,parent)
{
    QStringList header;
    header << "ID" << "priority" << "<duration>" << "<latency>" << "duration" << "latency" << "executions";
    setHorizontalHeaderLabels(header);

    setAttribute(Qt::WA_DeleteOnClose);
    show();
}

QThreadingWidget::~QThreadingWidget()
{
    delete ui;
}

bool QThreadingWidget::hasThread(quint8 id)
{
    return (findThread(id) >= 0);
}

int QThreadingWidget::findThread(quint8 id)
{
    for(unsigned int k = 0; k<threads.length() ; k++){
        if(threads[k].id == id){
            return k;
        }
    }
    return -1;
}

void QThreadingWidget::layoutRow(int row)
{
    for(int k=0; k<7 ; k++){
        setItem(row,k,new QTableWidgetItem(0));
        item(row,k)->setTextAlignment(Qt::AlignRight);
    }

    item(row,0)->setTextAlignment(Qt::AlignLeft);
    item(row,1)->setTextAlignment(Qt::AlignCenter);
}

void QThreadingWidget::updateThreadAt(int row, thread_t thread)
{
    item(row,0)->setText(QString::number(thread.id));
    item(row,1)->setText(QString::number(thread.priority));
    item(row,2)->setText(QString::number(thread.duration/thread.executions));
    item(row,3)->setText(QString::number(thread.latency/thread.executions));
    item(row,4)->setText(QString::number(thread.duration));
    item(row,5)->setText(QString::number(thread.latency));
    item(row,6)->setText(QString::number(thread.executions));
}

void QThreadingWidget::mavlinkMsgReceived(mavlink_message_t msg)
{
    switch(msg.msgid){
        case MAVLINK_MSG_ID_THREAD_INFO:{
            mavlink_thread_info_t thread_info;
            mavlink_msg_thread_info_decode(&msg, &thread_info);

            thread_t thread;
            thread.id = thread_info.ID;
            thread.priority = thread_info.priority;
            thread.duration = thread_info.total_duration;
            thread.latency = thread_info.total_latency;
            thread.executions = thread_info.number_of_executions;

            int index = findThread(thread.id);
            if(index>=0){
                threads[index] = thread;
            } else {
                threads.append(thread);
                insertRow(rowCount());
                index=rowCount()-1;
                layoutRow(index);
            }

            updateThreadAt(index,thread);
        break;}
    }
}
