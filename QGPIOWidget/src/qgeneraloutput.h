#ifndef QGENERALOUTPUT_H
#define QGENERALOUTPUT_H

#include <qgeneralio.h>
#include <QLayout>
#include <QLineEdit>
#include <QAbstractSpinBox>
#include <QLocalServer>
#include <QLocalSocket>

class QGeneralOutput : public QGeneralIO
{
    Q_OBJECT
public:
    explicit QGeneralOutput(QString label = "", QWidget *parent = 0);

    virtual double valueDouble() = 0;
    virtual void setValueDouble(double value) = 0;

protected:
    virtual QAbstractSpinBox* getSpinBox() = 0;
    void setup();

public slots:
    virtual void handleReadyRead() = 0;

};

#endif // QGENERALOUTPUT_H
