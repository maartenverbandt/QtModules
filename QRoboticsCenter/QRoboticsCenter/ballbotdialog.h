#ifndef BALLBOTDIALOG_H
#define BALLBOTDIALOG_H

#include <QDialog>
#include <mavlink.h>

namespace Ui {
class BallbotDialog;
}

class BallbotDialog : public QDialog
{
    Q_OBJECT

public:
    explicit BallbotDialog(QWidget *parent = 0);
    ~BallbotDialog();

private:
    Ui::BallbotDialog *ui;

public slots:
    //void mavlinkMsgReceived(mavlink_message_t msg);

    //void writeBallbotSettings(QByteArray settings);
    //void loadBallbotSettings();

private slots:
    void on_no_control_pushButton_pressed();
    void on_attituce_control_pushButton_pressed();
    void on_console_control_pushButton_pressed();
    void on_position_control_pushButton_pressed();

signals:
    //void mavlinkMsgSend(mavlink_message_t msg);

    //void ballbotSettingsReceived(QByteArray settings);

};

#endif // BALLBOTDIALOG_H
