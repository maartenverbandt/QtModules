#include "qconnectioninfodatanodewidget.h"

QConnectionInfoDataNodeWidget::QConnectionInfoDataNodeWidget(QWidget *parent) :
    QDataNodeWidget(parent), _widget(new QConnectionInfoWidget(parent))
{

}

QWidget *QConnectionInfoDataNodeWidget::w()
{
    return _widget;
}

void QConnectionInfoDataNodeWidget::receive(heartbeat_t)
{
    _widget->msgReceived(0);
}

void QConnectionInfoDataNodeWidget::receive(gpio_t)
{
    _widget->msgReceived(1);
}

void QConnectionInfoDataNodeWidget::receive(pose_t)
{
    _widget->msgReceived(50);
}
