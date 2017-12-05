#ifndef QGAMEPADCOMMAND_H
#define QGAMEPADCOMMAND_H

#include <qdataportinterface.h>
#include <qcommandmapwidget.h>

class QGamepadCommand : public QDataPortInterface
{
public:
    QGamepadCommand(QString name, QWidget *parent = 0);

    virtual QWidget *w();
    QCommandMapWidget *cmdWidget();

    virtual bool enabled();
    virtual void reset();

protected:
    QCommandMapWidget* _cmd_widget;

};

#endif // QGAMEPADCOMMAND_H
