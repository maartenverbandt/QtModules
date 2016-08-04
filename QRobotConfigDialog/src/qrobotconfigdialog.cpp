#include "qrobotconfigdialog.h"
#include "ui_qrobotconfigdialog.h"

QRobotConfigDialog::QRobotConfigDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QRobotConfigDialog)
{
    ui->setupUi(this);
}

QRobotConfigDialog::~QRobotConfigDialog()
{
    delete ui;
}

void QRobotConfigDialog::addGroup(QString group)
{
    QStringList list;
    list.append(group);
    list.append("");
    QTreeWidgetItem *item = new QTreeWidgetItem(list,100);

    ui->treeWidget->addTopLevelItem(item);
}

void QRobotConfigDialog::addParameter(QTreeWidgetItem *item, QString group)
{
    if(group.isNull()){
        ui->treeWidget->addTopLevelItem(item);
    } else {
        QList<QTreeWidgetItem*> parents = ui->treeWidget->findItems(group,Qt::MatchExactly);
        if(!parents.isEmpty()){
            parents[0]->addChild(item);
        } else {
            ui->treeWidget->addTopLevelItem(item);
        }
    }
}

void QRobotConfigDialog::on_open_pushButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(0,
        tr("Open EEPROM File"), QDir::currentPath(), tr("EEPROM Files (*.epr)"));
    QFile file(fileName,this);
    file.open(QIODevice::ReadOnly);
    fromByteArray(file.readAll());
    file.close();
    updateWidgets();
}

void QRobotConfigDialog::on_save_pushButton_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(0,
        tr("Save EEPROM File"), QDir::currentPath() + "/untitled.epr", tr("EEPROM Files (*.epr)"));
    QFile file(fileName,this);
    updateParameters();
    file.open(QIODevice::WriteOnly);
    file.write(getByteArray());
    file.close();
}

void QRobotConfigDialog::on_load_pushButton_clicked()
{
    emit readRobotSettings();
}

void QRobotConfigDialog::on_send_pushButton_clicked()
{
    emit writeRobotSettings(getByteArray());
}

void QRobotConfigDialog::updateWidgets()
{
    for(int k = 0;k<_parameters.length();k++){
        _parameters[k]->updateWidget();
    }
}

void QRobotConfigDialog::updateParameters()
{
    for(int k = 0;k<_parameters.length();k++){
        _parameters[k]->updateParameter();
    }
}
