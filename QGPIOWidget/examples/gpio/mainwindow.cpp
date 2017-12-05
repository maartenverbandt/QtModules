#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    gpio(new QGPIODataNodeWidget(0)),
    sig(new QGPIOSignalGenerator(0))
{
    ui->setupUi(this);
    setCentralWidget(gpio->w());
    sig->connectTo(gpio);
}

MainWindow::~MainWindow()
{
    delete ui;
}
