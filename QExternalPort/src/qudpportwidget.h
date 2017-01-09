#ifndef QUDPPORTWIDGET_H
#define QUDPPORTWIDGET_H

#include <QWidget>
#include <qudpport.h>

namespace Ui {
class QUdpPortWidget;
}

class QUdpPortWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QUdpPortWidget(quint64 line_size, QWidget *parent = 0);
    ~QUdpPortWidget();

    QUdpPort* getUdpPort();
    QByteArray readLine();

private slots:
    void on_incoming_port_valueChanged(int arg1);
    void on_outgoing_port_valueChanged(int arg1);

private:
    Ui::QUdpPortWidget *ui;
    QUdpPort* _udp_port;

};

#endif // QUDPPORTWIDGET_H
