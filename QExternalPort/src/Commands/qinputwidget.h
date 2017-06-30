#ifndef QCSVINPUTWIDGET_H
#define QCSVINPUTWIDGET_H

#include <QWidget>
#include <QLayout>
#include <QDebug>
#include <qdataportinterface.h>

class QInputWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QInputWidget(QString name, QWidget *parent = 0);

    void addPort(QDataPortInterface *port);
    virtual QList<QVariant> read();
    void reset();

protected:
    QList<QDataPortInterface*> ports;

};

#endif // QCSVINPUTWIDGET_H
