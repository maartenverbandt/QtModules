#ifndef QTHREADINGWIDGET_H
#define QTHREADINGWIDGET_H

#include <QTableWidget>
#include <mavlink.h>

typedef struct thread_t{
    quint8 id;
    quint8 priority;
    quint32 time;
    quint32 duration;
    quint32 latency;
    quint32 executions;
} thread_t;

namespace Ui {
class QThreadingWidget;
}

class QThreadingWidget : public QTableWidget
{
    Q_OBJECT

public:
    explicit QThreadingWidget(QWidget *parent = 0);
    ~QThreadingWidget();

    bool hasThread(quint8 id);
    int findThread(quint8 id);

private:
    Ui::QThreadingWidget *ui;
    QList<thread_t> threads;

    void layoutRow(int row);
    void updateThreadAt(int row, thread_t thread);

public slots:
    void mavlinkMsgReceived(mavlink_message_t msg);

};

#endif // QTHREADINGWIDGET_H
