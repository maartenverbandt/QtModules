#ifndef QGENERALOUTPUT_H
#define QGENERALOUTPUT_H

#include <QWidget>
#include <QLayout>
#include <QLineEdit>
#include <QAbstractSpinBox>
#include <QLocalServer>
#include <QLocalSocket>

class QGeneralOutput : public QWidget
{
    Q_OBJECT
public:
    explicit QGeneralOutput(QString label = "", QWidget *parent = 0);

    QString text();
    void setText(QString text);

    QLineEdit *getLabel();
    void setMountPoint(QString mount_point);

    virtual double value() = 0;
    virtual void setValue(double value) = 0;

protected:
    QVector<QLocalSocket*> _sockets;

    virtual QAbstractSpinBox* getSpinBox() = 0;
    virtual void setup();

private:
    QLineEdit* _label;

    QLocalServer* _server;
    QString _mount_point;

signals:

public slots:
    void restartServer();
    void handleNewConnection();
    virtual void handleReadyRead();

};

#endif // QGENERALOUTPUT_H
