#ifndef QGENERALIO_H
#define QGENERALIO_H

#include <QWidget>
#include <QLayout>
#include <QLineEdit>
#include <QLocalServer>
#include <QLocalSocket>

class QGeneralIO : public QWidget
{
    Q_OBJECT
public:
    explicit QGeneralIO(QString label = "", QWidget *parent = 0);

    QString text();
    void setText(QString text);

    QLineEdit *getLabel();
    void setMountPoint(QString mount_point);

protected:
    QLocalSocket* _socket;

    virtual void setup(QWidget* w);

private:
    QLineEdit* _label;

    QLocalServer* _server;
    QString _mount_point;

public slots:
    void restartServer();
    void handleNewConnection();

};

#endif // QGENERALIO_H
