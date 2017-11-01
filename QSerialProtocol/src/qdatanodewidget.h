#ifndef QDATANODEWIDGET_H
#define QDATANODEWIDGET_H

#include <QWidget>
#include <qdatanode.h>

class QDataNodeWidget : public QDataNode
{
    Q_OBJECT
public:
    explicit QDataNodeWidget(QWidget *parent = 0);

    QWidget *w();

protected:
    QWidget *_w;

};

#endif // QDATANODEWIDGET_H
