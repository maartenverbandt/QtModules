#ifndef QPOSITIONCMDUDPPORT_H
#define QPOSITIONCMDUDPPORT_H

#include <qudpportwidget.h>
#include <qpositioncmdportinterface.h>
#include <qdebug.h>

class QPositionCmdUdpPort : public QObject, public QPositionCmdPortInterface
{
    Q_OBJECT

public:
    QPositionCmdUdpPort(QObject *parent = 0);

    mavlink_position_cmd_t getPositionCmdPacket();
    QVariant getPacket();
    QWidget* getWidget();

private:
    QUdpPortWidget* _udp_port;

};

#endif // QPOSITIONCMDUDPPORT_H
