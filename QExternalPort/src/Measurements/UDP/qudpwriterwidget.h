#ifndef QUDPWRITERWIDGET_H
#define QUDPWRITERWIDGET_H

#include <QWidget>
#include <qudpwriter.h>

namespace Ui {
class QUdpWriterWidget;
}

class QUdpWriterWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QUdpWriterWidget(QString name, QWidget *parent = 0);
    ~QUdpWriterWidget();

    QUdpWriter* getUdpWriter();
    void writeLine(QByteArray bytes);
    bool enabled();

private slots:
    void on_incoming_port_valueChanged(int arg1);

private:
    Ui::QUdpWriterWidget *ui;
    QUdpWriter* _udp_port;
};

#endif // QUDPWRITERWIDGET_H
