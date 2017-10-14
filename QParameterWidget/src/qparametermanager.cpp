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
    emit parameterAdded(parameter->name());
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

void QParameterManager::receive(mavlink_event_t event)
{

}

void QParameterManager::receive(mavlink_param_int_t param_int)
{
    //param_int.
}

void QParameterManager::receive(mavlink_param_float_t param_float)
{

}

void QParameterManager::updateParameter(QString name, QString value)
{
    bool ok;
    QParameter *parameter = findParameter(name,&ok);
    if(ok) {
        parameter->setValue(value);
    } else {
        qWarning() << "implementation error: parameter not found!";
    }
}


