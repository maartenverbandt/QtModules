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
    QList<QVariant> read();
    void reset();

private:
    QList<QDataPortInterface*> ports;

};

#endif // QCSVINPUTWIDGET_H
