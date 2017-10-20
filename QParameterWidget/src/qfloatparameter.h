#ifndef QFLOATPARAMETER_H
#define QFLOATPARAMETER_H

#include <qparameter.h>
#include <QDebug>

class QFloatParameter : public QParameter
{
public:
    QFloatParameter(QString name, int offset, float value, QObject *parent = 0);

    virtual const QString valueString();
    virtual void setValue(const QString value);
    virtual int type();

    void setValue(double value);
    float value();

private:
    float _value;

};

#endif // QFLOATPARAMETER_H
