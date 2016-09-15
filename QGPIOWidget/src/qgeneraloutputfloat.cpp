#include "qgeneraloutputfloat.h"

QGeneralOutputFloat::QGeneralOutputFloat(QString label, QWidget *parent) :
    QGeneralOutput(label, parent),
    _spinbox(new QDoubleSpinBox(this))
{
    setup();
    _spinbox->setRange(-1e100,1e100);
    _spinbox->setDecimals(4);
}

double QGeneralOutputFloat::value()
{
    return _spinbox->value();
}

void QGeneralOutputFloat::setValue(double value)
{
    _spinbox->setValue(value);
}

QAbstractSpinBox *QGeneralOutputFloat::getSpinBox()
{
    return _spinbox;
}

void QGeneralOutputFloat::handleReadyRead()
{
    while(_sockets[0]->bytesAvailable() >= 4){
        QByteArray data = _sockets[0]->read(4);
        qDebug() << data;
        float value = *(float*)data.data();
        _spinbox->setValue(value);
    }
}
