#ifndef QMAVLINKCONNECTIONINFODIALOG_H
#define QMAVLINKCONNECTIONINFODIALOG_H

#include <QDialog>
#include <QBrush>
#include <QString>
#include <QElapsedTimer>
#include <qmavlinkconnection.h>
#include "qcustomplot.h"

#define BAR_WIDTH       0.9
#define RATE_THRESHOLD  2.0
#define REFRESH_COUNT   20

namespace Ui {
class QMavlinkConnectionInfoDialog;
}

class QMavlinkConnectionInfoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit QMavlinkConnectionInfoDialog(QWidget *parent = 0);
    ~QMavlinkConnectionInfoDialog();

private:
    Ui::QMavlinkConnectionInfoDialog *ui;

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

    void addMsgID(int msgid);
    void updateAxis();
    void updateData();

public slots:
    void mavlinkMsgReceived(mavlink_message_t msg);
    void reset();

};

#endif // QMAVLINKCONNECTIONINFODIALOG_H
