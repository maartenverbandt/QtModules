#include "qcommandmap.h"

QCommandMap::QCommandMap()
{

}

void QCommandMap::add(QString command)
{
    _map.insert(command, NULL);
}

bool QCommandMap::map(QString command, QGamepadButton *button)
{
    if(_map.contains(command))
        _map[command] = button;

    return configured(command);
}

bool QCommandMap::configured(QString command)
{
    return (_map.contains(command) && (_map[command] == NULL));
}

double QCommandMap::value(QString command)
{
    QGamepadButton* b = _map[command];
    double r = 0.0;
    if(b != NULL){
        r = b->value();
    }
    return r;
}

QList<QString> QCommandMap::commands()
{
    return _map.keys();
}
