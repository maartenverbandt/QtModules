#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <mavlink.h>
#include <QTime>
#include <QUdpSocket>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void timerEvent(QTimerEvent *);

private:
    Ui::MainWindow *ui;
    QUdpSocket* s;

signals:
    void positionCmdSend(mavlink_position_cmd_t position_cmd);

private slots:
    void on_pushButton_clicked();
};


#endif // MAINWINDOW_H
