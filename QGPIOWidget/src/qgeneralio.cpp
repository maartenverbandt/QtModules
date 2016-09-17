#include "qgeneralio.h"

QGeneralIO::QGeneralIO(QString label, QWidget *parent) :
    QWidget(parent),
    _label(new QLineEdit(label)),
    _socket(NULL),
    _server(new QLocalServer(this))
{
    QObject::connect(_server,SIGNAL(newConnection()),this,SLOT(handleNewConnection()));
}

QString QGeneralIO::text()
{
    return _label->text();
}

void QGeneralIO::setText(QString text)
{
    _label->setText(text);
}

QLineEdit *QGeneralIO::getLabel()
{
    return _label;
}

void QGeneralIO::setMountPoint(QString mount_point)
{
    _mount_point = mount_point;
    restartServer();
}

void QGeneralIO::setup(QWidget *w)
{
    this->setLayout(new QBoxLayout(QBoxLayout::LeftToRight,this));
    this->layout()->setContentsMargins(0,0,0,0);
    this->layout()->addWidget(_label);
    this->layout()->addWidget(w);

    // Setup server
    QObject::connect(_label,SIGNAL(textChanged(QString)),this,SLOT(restartServer()));
    restartServer();
}

void QGeneralIO::restartServer()
{
    if(_server->isListening())
        _server->close();

    qDebug() << _mount_point + ":" + _label->text();
    _server->listen(_mount_point + ":" + _label->text());
}

void QGeneralIO::handleNewConnection()
{
    if(_socket == NULL){
        _socket = _server->nextPendingConnection();
        _socket->open(QIODevice::ReadWrite);
        QObject::connect(_socket,SIGNAL(readyRead()),this,SLOT(handleReadyRead()));
    } else {
        qDebug() << "Server is already connected.";
    }
}
