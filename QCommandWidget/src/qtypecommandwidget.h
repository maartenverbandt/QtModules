#ifndef QTYPECOMMANDWIDGET_H
#define QTYPECOMMANDWIDGET_H

#include <QWidget>
#include <QLayout>
#include <QDebug>
#include <qtypecommandinterface.h>

class QTypeCommandWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QTypeCommandWidget(QString name, QWidget *parent = 0);

    void add(QTypeCommandInterface *port);
    virtual void transmitTo(QDataNode *other);

    virtual void transmit();
    void reset();

protected:
    QVBoxLayout *_layout = new QVBoxLayout(this);
    QList<QDataPortInterface *> _ports;

};

#endif // QTYPECOMMANDWIDGET_H
