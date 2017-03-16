#include "qcommandmap.h"

QCommandMap::QCommandMap()
{

}

void QCommandMap::add(QString command)
{
    _map.insert(command, QGamepadButton::Disabled());
}

bool QCommandMap::map(QString command, QGamepadButton button)
{
    if(_map.contains(command))
        _map[command] = button;

    return configured(command);
}

bool QCommandMap::configured(QString command)
{
    return _map.contains(command) && _map[command].isDisabled();
}

double QCommandMap::value(QString command)
{
    return _map[command].value();
}

QList<QString> QCommandMap::commands()
{
    return _map.keys();
}

bool QCommandMap::setValue(QGamepadButton button)
{
    QList<QString> keys = _map.keys();
    for(int i = 0; i<_map.size(); i++){
        if(_map[keys[0]] == button){
            _map[keys[0]].setValue(button.value());
            qDebug() << "Button" <<  button.buttonID() << "value changed";
        }
    }
    /*QList<QString> keys = _map.keys(button);
    if(keys.size()>0){
        _map[keys[0]].setValue(button.value());
        qDebug() << "Button" <<  button.buttonID() << "value changed";
    }*/
    return true;
}
