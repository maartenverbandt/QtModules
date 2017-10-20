#include "qparametermanager.h"

QParameterManager::QParameterManager(QObject *parent) :
    QDataNode(parent)
{

}

const QList<QParameter *> QParameterManager::parameters()
{
    return _parameter_map.values();
}

void QParameterManager::addParameter(QParameter *parameter)
{
    parameter->setParent(this);
    _parameter_map[parameter->name()] = parameter;
    emit parameterAdded(parameter->name(), parameter->valueString());
}

bool QParameterManager::hasParameter(const QString name)
{
    return _parameter_map.contains(name);
}

QParameter *QParameterManager::findParameter(const QString name, bool *ok)
{
    if(hasParameter(name)){
        *ok = true;
        return _parameter_map[name];
    } else {
        *ok = false;
        return Q_NULLPTR;
    }
}

void QParameterManager::receive(param_int_t param_int)
{
    QString name = QString(QByteArray(param_int.name,10));
    if(hasParameter(name)) {
        updateParameter(name, QString::number(param_int.value));
    } else {
        addParameter(new QIntegerParameter(name, param_int.pointer, param_int.value));
    }
}

void QParameterManager::receive(param_float_t param_float)
{
    QString name = QString(QByteArray(param_float.name,10));
    if(hasParameter(name)) {
        updateParameter(name, QString::number(param_float.value));
    } else {
        addParameter(new QFloatParameter(name, param_float.pointer, param_float.value));
    }
}

void QParameterManager::updateParameter(QString name, QString value)
{
    bool ok;
    QParameter *parameter = findParameter(name,&ok);
    if(ok) {
        if(value.compare(parameter->valueString()) != 0) {
            parameter->setValue(value);
            emit parameterChanged(name, value);
        }
    } else {
        qWarning() << "implementation error: parameter not found!";
    }
}

void QParameterManager::transmitParameters()
{
    QList<QParameter*> list = _parameter_map.values();
    for(int k=0; k<list.size(); k++) {
        switch(list[k]->type()) {
        case QParameter::INTEGER : {
            param_int_t m;
            memcpy(m.name, list[k]->name().toLocal8Bit().data(), list[k]->name().size()+1);
            m.pointer = list[k]->offset();
            m.value = static_cast<QIntegerParameter*>(list[k])->value();
            emit transmit(m);
            break;}

        case QParameter::FLOAT : {
            param_float_t m;
            memcpy(m.name, list[k]->name().toLocal8Bit().data(), list[k]->name().size()+1);
            m.pointer = list[k]->offset();
            m.value = static_cast<QFloatParameter*>(list[k])->value();
            emit transmit(m);
            break;}
        }
    }
}

void QParameterManager::requestParameters()
{
    event_t event;
    event.type = PARAMETERS_REQUEST_SEND;
    transmit(event);
}

void QParameterManager::storeParameters()
{
    event_t event;
    event.type = PARAMETERS_REQUEST_ST0RE;
    transmit(event);
}


