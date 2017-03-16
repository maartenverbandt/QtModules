#ifndef QGAMEPADCOMMAND_H
#define QGAMEPADCOMMAND_H

#include <qdataportinterface.h>
#include <qcommandmapwidget.h>
#include <qgamepadinputwidget.h>

class QGamepadCommand : public QDataPortInterface
{
public:
    QGamepadCommand(QString name, QGamepadInputWidget *parent = 0);

    virtual QVariant getPacket() = 0;
    virtual QWidget *getWidget();
    QCommandMapWidget *cmdWidget();

    virtual bool enabled();
    virtual void reset();

protected:
    QCommandMapWidget* _cmd_widget;

};

#endif // QGAMEPADCOMMAND_H
