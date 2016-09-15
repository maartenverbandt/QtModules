#include "qgeneraloutput.h"

QGeneralOutput::QGeneralOutput(QString label, QWidget *parent) :
    QWidget(parent),
    _label(new QLineEdit(label)),
    _server(new QLocalServer(this))
{
    QObject::connect(_server,SIGNAL(newConnection()),this,SLOT(handleNewConnection()));
}

QString QGeneralOutput::text()
{
    return _label->text();
}

void QGeneralOutput::setText(QString text)
{
    _label->setText(text);
}

QLineEdit *QGeneralOutput::getLabel()
{
    return _label;
}

void QGeneralOutput::setMountPoint(QString mount_point)
{
    _mount_point = mount_point;
    restartServer();
}

void QGeneralOutput::setup()
{
    this->setLayout(new QBoxLayout(QBoxLayout::LeftToRight,this));
    this->layout()->setContentsMargins(0,0,0,0);
    this->layout()->addWidget(_label);
    this->layout()->addWidget(getSpinBox());
    getSpinBox()->setFixedWidth(100);

    // Setup server
    QObject::connect(_label,SIGNAL(textChanged(QString)),this,SLOT(restartServer()));
    restartServer();
}

void QGeneralOutput::restartServer()
{
    if(_server->isListening())
        _server->close();

    qDebug() << _mount_point + ":" + _label->text();
    _server->listen(_mount_point + ":" + _label->text());
}

void QGeneralOutput::handleNewConnection()
{
    QLocalSocket* socket = _server->nextPendingConnection();
    socket->open(QIODevice::ReadOnly);
    QObject::connect(socket,SIGNAL(readyRead()),this,SLOT(handleReadyRead()));
    _sockets.append(socket);

}

void QGeneralOutput::handleReadyRead()
{

}
