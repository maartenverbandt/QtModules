#include "qudpreaderwidget.h"
#include "ui_qudpportwidget.h"

QUdpReaderWidget::QUdpReaderWidget(quint64 line_size, QString name, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QUdpReaderWidget),
    _udp_port(new QUdpReader(line_size,parent))
{
    ui->setupUi(this);
    ui->incoming_port->setRange(0,65535);
    ui->groupBox->setTitle(name);
    this->updatePort();
    this->setObjectName(name);
}

QUdpReaderWidget::~QUdpReaderWidget()
{
    delete ui;
}

QUdpReader *QUdpReaderWidget::getUdpReader()
{
    return _udp_port;
}

QByteArray QUdpReaderWidget::readLine()
{
    QByteArray bytes = _udp_port->readLine();
    ui->label_3->setText(QString::number(_udp_port->linesRead()));

    return bytes;
}

bool QUdpReaderWidget::enabled()
{
    return ui->groupBox->isChecked();
}


void QUdpReaderWidget::updatePort()
{
    ui->incoming_port->setValue(_udp_port->getPort());
}

void QUdpReaderWidget::on_incoming_port_valueChanged(int arg1)
{
    _udp_port->setPort(arg1);
}
