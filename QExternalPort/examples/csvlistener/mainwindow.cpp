#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    d(new QPositionCmdPortDialog(0))
{
    ui->setupUi(this);
    menuBar()->addAction(d->getPopupAction());

    QObject::connect(d,SIGNAL(positionCmdPacket(mavlink_position_cmd_t)),this,SLOT(positionCmdCatch(mavlink_position_cmd_t)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::positionCmdCatch(mavlink_position_cmd_t position_cmd)
{
    qDebug() << position_cmd.x << position_cmd.y << position_cmd.z;
}
