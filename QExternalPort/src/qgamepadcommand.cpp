#include "qgamepadcommand.h"

QGamepadCommand::QGamepadCommand(QObject *parent) :
    QObject(parent)
{

}

bool QGamepadCommand::configured(QString command)
{
    return (_map.contains(command) && (_map[command] == NULL));
}

double QGamepadCommand::value(QString command)
{
    QGamepadButton* b = _map[command];
    double r = 0.0;
    if(b != NULL){
        r = b->value();
    }
    return r;
}

void QGamepadCommand::addCommand(QString command)
{
    _map.insert(command, NULL);
}
