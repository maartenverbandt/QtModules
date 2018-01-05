#ifndef QROBOTCOMMANDWIDGET_H
#define QROBOTCOMMANDWIDGET_H

#include <qcommandwidget.h>
#include <qgpiocsvcommand.h>
#include <qtypeudpcommand.h>
#include <qgamepadcommandwidget.h>
#include <qvelocitygamepadcommand.h>

class QRobotCommandWidget : public QCommandWidget
{
    Q_OBJECT
public:
    explicit QRobotCommandWidget(QWidget *parent = 0);

protected:
    QTypeCommandWidget *_csv;
    QTypeCommandWidget *_udp;
    QGamepadCommandWidget *_gamepad;

};

#endif // QROBOTCOMMANDWIDGET_H
