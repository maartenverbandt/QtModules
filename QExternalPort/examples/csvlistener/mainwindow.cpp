#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::positionCmdCatch(mavlink_position_cmd_t position_cmd)
{
    qDebug() << position_cmd.x << position_cmd.y << position_cmd.z;
}
