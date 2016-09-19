#ifndef QTHREADINGWIDGET_H
#define QTHREADINGWIDGET_H

#include <QTableWidget>
#include <QAction>

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

Q_DECLARE_METATYPE(thread_t)

/*namespace Ui {
class QThreadingWidget;
}*/

class QThreadingWidget : public QTableWidget
{
    Q_OBJECT

public:
    explicit QThreadingWidget(QWidget *parent = 0);
    ~QThreadingWidget();

    bool hasThread(int id);
    int findThread(int id);

    QAction *getPopupAction();

private:
    //Ui::QThreadingWidget *ui;
    QList<thread_t> threads;
    QAction *_popup;

    void populateRow(int row);

protected slots:
    void closeEvent(QCloseEvent *e);

public slots:
    void updateThreadInfo(thread_t);

};

#endif // QTHREADINGWIDGET_H
