#ifndef QCOMMANDMAP_H
#define QCOMMANDMAP_H

#include <qgamepadbutton.h>
#include <QMap>
#include <qdebug.h>

class QCommandMap
{
public:
    QCommandMap();

    void add(QString command);
    bool map(QString command, QGamepadButton button);
    bool configured(QString command);
    double value(QString command);

    QList<QString> commands();

    bool setValue(QGamepadButton button);

private:
    QMap<QString,QGamepadButton> _map;

};

#endif // QCOMMANDMAP_H
