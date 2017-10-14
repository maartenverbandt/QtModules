#ifndef QFLOATPARAMETER_H
#define QFLOATPARAMETER_H

#include <qparameter.h>
#include <QDebug>

class QFloatParameter : public QParameter
{
public:
    QFloatParameter(QString name, float value, QObject *parent = 0);

    virtual const QString valueString();
    virtual void setValue(const QString value);
    void setValue(double value);
    virtual int type();

private:
    float _value;

};

#endif // QFLOATPARAMETER_H
