#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    d(new QPositionCmdPortDialog(0)),
    s(new QUdpSocket(this))
{
    ui->setupUi(this);
    menuBar()->addAction(d->getPopupAction());

    QObject::connect(d,SIGNAL(positionCmdPacket(mavlink_position_cmd_t)),this,SLOT(positionCmdCatch(mavlink_position_cmd_t)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timerEvent(QTimerEvent *)
{
    mavlink_position_cmd_t cmd;
    cmd.x = QTime::currentTime().msec();
    cmd.y = 1;
    cmd.z = 2;
    cmd.xFF = 10;
    cmd.yFF = 11;
    cmd.zFF = 12;

    s->writeDatagram((char*)(&cmd),MAVLINK_MSG_ID_POSITION_CMD_LEN,QHostAddress::LocalHost,ui->spinBox->value());
}

void MainWindow::positionCmdCatch(mavlink_position_cmd_t position_cmd)
{
    qDebug() << position_cmd.x << position_cmd.y << position_cmd.z;
    qDebug() << position_cmd.xFF << position_cmd.yFF << position_cmd.zFF;
}

void MainWindow::on_pushButton_clicked()
{
    startTimer(50,Qt::PreciseTimer);
}
