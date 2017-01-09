#include "qudpportwidget.h"
#include "ui_qudpportwidget.h"

QUdpPortWidget::QUdpPortWidget(quint64 line_size, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QUdpPortWidget),
    _udp_port(new QUdpPort(line_size))
{
    ui->setupUi(this);
    ui->incoming_port->setRange(0,65535);
    ui->incoming_port->setValue(_udp_port->getPort());
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
    QByteArray bytes = _udp_port->readLine();
    ui->label_3->setText(QString::number(_udp_port->linesRead()));

    return bytes;
}

void QUdpPortWidget::on_incoming_port_valueChanged(int arg1)
{
    _udp_port->setPort(arg1);
}

void QUdpPortWidget::on_outgoing_port_valueChanged(int arg1)
{
    //change outgoing port number
}
