#ifndef QUDPPORTWIDGET_H
#define QUDPPORTWIDGET_H

#include <QWidget>
#include <qudpreader.h>

namespace Ui {
class QUdpPortWidget;
}

class QUdpReaderWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QUdpReaderWidget(quint64 line_size, QString name, QWidget *parent = 0);
    ~QUdpReaderWidget();

    QUdpReader* getUdpReader();
    QByteArray readLine();
    bool enabled();

private slots:
    void on_incoming_port_valueChanged(int arg1);

private:
    Ui::QUdpPortWidget *ui;
    QUdpReader* _udp_port;

};

#endif // QUDPPORTWIDGET_H
