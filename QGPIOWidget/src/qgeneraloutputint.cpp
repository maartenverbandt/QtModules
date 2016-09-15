#include "qgeneraloutputint.h"

QGeneralOutputInt::QGeneralOutputInt(QString label, QWidget *parent) :
    QGeneralOutput(label, parent),
    _spinbox(new QSpinBox(this))
{
    setup();
    _spinbox->setRange(-1e9,1e9);
}

double QGeneralOutputInt::value()
{
    return _spinbox->value();
}

void QGeneralOutputInt::setValue(double value)
{
    _spinbox->setValue(value);
}

QAbstractSpinBox *QGeneralOutputInt::getSpinBox()
{
    return _spinbox;
}

void QGeneralOutputInt::handleReadyRead()
{
    while(_sockets[0]->bytesAvailable() >= 4){
        QByteArray data = _sockets[0]->read(4);
        int value = *(int*)data.data();
        _spinbox->setValue(value);
    }
}
