#include "qudpportwidget.h"
#include "ui_qudpportwidget.h"

QUdpPortWidget::QUdpPortWidget(quint64 line_size, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QUdpPortWidget),
    _udp_port(new QUdpPort(line_size))
{
    ui->setupUi(this);
}

QUdpPortWidget::~QUdpPortWidget()
{
    delete ui;
}

QUdpPort *QUdpPortWidget::getUdpPort()
{
    return _udp_port;
}

QByteArray QUdpPortWidget::readLine()
{
    _udp_port->readLine();
    ui->label_3->setText(_udp_port->linesRead());
}

void QUdpPortWidget::on_spinBox_valueChanged(int arg1)
{
    _udp_port->setPort(arg1);
}
