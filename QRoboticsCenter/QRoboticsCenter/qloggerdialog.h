#ifndef QLOGGERDIALOG_H
#define QLOGGERDIALOG_H

#include <QDialog>
#include <QDebug>
#include <mavlink.h>
#include <QFile>
#include <QDir>
#include <QDateTime>

#ifdef LOGGER_MATIO
#include <matio.h>
#endif

namespace Ui {
class QLoggerDialog;
}

class QLoggerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit QLoggerDialog(QWidget *parent = 0);
    ~QLoggerDialog();

public slots:
    void mavlinkMsgReceived(mavlink_message_t msg);

private slots:
    void on_recordButton_clicked(bool checked);

private:
    Ui::QLoggerDialog *ui;
    QVector<double> time_vector;
    QVector<int> int_vector[4];
    QVector<double> double_vector[8];

    int start;
};

#endif // QLOGGERDIALOG_H
