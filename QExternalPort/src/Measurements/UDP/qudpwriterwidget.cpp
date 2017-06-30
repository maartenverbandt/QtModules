#include "qudpwriterwidget.h"
#include "ui_qudpwriterwidget.h"

QUdpWriterWidget::QUdpWriterWidget(QString name, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QUdpWriterWidget),
    _udp_port(new QUdpWriter(parent))
{
    ui->setupUi(this);
    ui->incoming_port->setRange(0,65535);
    ui->incoming_port->setValue(_udp_port->getPort());
    ui->groupBox->setTitle(name);
}

QUdpWriterWidget::~QUdpWriterWidget()
{
    delete ui;
}

QUdpWriter *QUdpWriterWidget::getUdpWriter()
{
    return _udp_port;
}

void QUdpWriterWidget::writeLine(QByteArray bytes)
{
    _udp_port->writeLine(bytes);
    ui->label_3->setText(QString::number(_udp_port->linesWritten()));
}

bool QUdpWriterWidget::enabled()
{
    return ui->groupBox->isChecked();
}

void QUdpWriterWidget::on_incoming_port_valueChanged(int arg1)
{
    _udp_port->setPort(arg1);
}
