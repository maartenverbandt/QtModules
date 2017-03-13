#ifndef QVELOCITYGAMEPADCOMMAND_H
#define QVELOCITYGAMEPADCOMMAND_H

#include <qcommandmapwidget.h>
#include <mavlink.h>

class QVelocityGamepadCommand : public QDataPortInterface
{
public:
    QVelocityGamepadCommand(QGamepadInputWidget *parent = 0);

    mavlink_velocity_cmd_t getVelocityCmdPacket();
    virtual QVariant getPacket();
    virtual QWidget *getWidget();

    virtual bool enabled();
    virtual void reset();

private:
    QCommandMapWidget* _cmd_widget;

};

#endif // QVELOCITYGAMEPADCOMMAND_H
