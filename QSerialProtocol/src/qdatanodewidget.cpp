#include "qdatanodewidget.h"

QDataNodeWidget::QDataNodeWidget(QWidget *parent) :
    QDataNode(parent), _w(NULL)
{
    //do nothing
}

QWidget *QDataNodeWidget::w()
{
    return _w;
}
