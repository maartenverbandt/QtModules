#ifndef QCONNECTIONINFODATANODEWIDGET_H
#define QCONNECTIONINFODATANODEWIDGET_H

#include <qdatanodewidget.h>
#include <qconnectioninfowidget.h>

class QConnectionInfoDataNodeWidget : public QDataNodeWidget
{
public:
    explicit QConnectionInfoDataNodeWidget(QWidget *parent = 0);
    virtual QWidget *w();

private:
    QConnectionInfoWidget *_widget;

public slots:
    virtual void receive(heartbeat_t);
    virtual void receive(gpio_t);
    virtual void receive(pose_t);

};

#endif // QCONNECTIONINFODATANODEWIDGET_H