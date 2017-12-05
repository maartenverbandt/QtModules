#ifndef QCONNECTIONINFOWIDGET_H
#define QCONNECTIONINFOWIDGET_H

#include <QDialog>
#include <QBrush>
#include <QString>
#include <QElapsedTimer>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <qserialprotocol.h>
#include <qcustomplot.h>

#define BAR_WIDTH       0.9
#define RATE_THRESHOLD  2.0
#define REFRESH_COUNT   20

class QConnectionInfoWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QConnectionInfoWidget(QWidget *parent = 0);

protected:
    virtual QSize sizeHint() const;

private:
    QCustomPlot *_plot;
    QCPBars *_bars_count;
    QCPBars *_bars_rate;

    QVector<int>    _message_id;
    QVector<int>    _sort_id;
    QVector<int>    _message_counter;

    QVector<double> _tick_pos;
    QVector<QString> _tick_label;
    QVector<double> _bar_pos;
    QVector<double> _bar_count_val;
    QVector<double> _bar_rate_val;

    QElapsedTimer _timer;
    unsigned long _msg_received;

    void setup();

    void addMsgID(int msgid);
    void updateAxis();
    void updateData();

public slots:
    void msgReceived(int id);
    void reset();

};

#endif // QCONNECTIONINFOWIDGET_H
