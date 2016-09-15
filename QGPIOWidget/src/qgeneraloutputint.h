#ifndef QGENERALOUTPUTINT_H
#define QGENERALOUTPUTINT_H

#include <qgeneraloutput.h>
#include <QSpinBox>

class QGeneralOutputInt : public QGeneralOutput
{
    Q_OBJECT

public:
    QGeneralOutputInt(QString label = "", QWidget *parent = 0);

    double value();
    void setValue(double value);

private:
    QAbstractSpinBox* getSpinBox();
    QSpinBox* _spinbox;

public slots:
    void handleReadyRead();

};

#endif // QGENERALOUTPUTINT_H
