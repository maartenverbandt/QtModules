#ifndef QTHREADINGWIDGET_H
#define QTHREADINGWIDGET_H

#include <QTableWidget>
#include <QAction>
#include <thread.h>
#include <mavlink.h>

typedef struct thread_t{
    quint8 id;
    quint8 priority;
    quint32 time;
    quint32 average_duration;
    quint32 average_latency;
    quint32 duration;
    quint32 latency;
    quint32 executions;
} thread_t;

class QThreadingWidget : public QTableWidget
{
    Q_OBJECT

public:
    explicit QThreadingWidget(QWidget *parent = 0);

    bool hasThread(int id);
    int findThread(int id);

private:
    QList<Thread> _threads;
    void populateRow(int row);
    void updateWidget();
    void updateWidget(int index);

public slots:
    void updateThread(Thread thread);

};

//Q_DECLARE_METATYPE(mavlink_thread_info_t)

#endif // QTHREADINGWIDGET_H
