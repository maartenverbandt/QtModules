#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    s(new QUdpSocket(this))
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timerEvent(QTimerEvent *)
{
    position_cmd_t cmd;
    cmd.x = QTime::currentTime().msec();
    cmd.y = 1;
    cmd.z = 2;
    cmd.xFF = 10;
    cmd.yFF = 11;
    cmd.zFF = 12;

    s->writeDatagram((char*)(&cmd),sizeof(cmd),QHostAddress::LocalHost,ui->spinBox->value());
}

void MainWindow::on_pushButton_clicked()
{
    startTimer(10,Qt::PreciseTimer);
}
