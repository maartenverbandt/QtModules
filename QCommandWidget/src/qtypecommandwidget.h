#ifndef QTYPECOMMANDWIDGET_H
#define QTYPECOMMANDWIDGET_H

#include <QWidget>
#include <QLayout>
#include <QDebug>
#include <qtypecommandinterface.h>

class QCommandTypeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QCommandTypeWidget(QString name, QWidget *parent = 0);

    void add(QDataPortInterface *port);
    virtual void transmitTo(QDataNode *other);

    virtual void transmit();
    void reset();

protected:
    QList<QDataPortInterface *> _ports;

};

#endif // QTYPECOMMANDWIDGET_H
