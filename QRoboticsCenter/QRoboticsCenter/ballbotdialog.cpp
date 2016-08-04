#include "ballbotdialog.h"
#include "ui_ballbotdialog.h"

BallbotDialog::BallbotDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BallbotDialog)
{
    ui->setupUi(this);
}

BallbotDialog::~BallbotDialog()
{
    delete ui;
}

void BallbotDialog::on_no_control_pushButton_pressed()
{
    // Disable the controller
}

void BallbotDialog::on_attituce_control_pushButton_pressed()
{
    // Enable the attitude controller
}

void BallbotDialog::on_console_control_pushButton_pressed()
{
    // Enable velocity control
}

void BallbotDialog::on_position_control_pushButton_pressed()
{
    // Enable position control
}
