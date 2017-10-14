#ifndef QINTEGERPARAMETER_H
#define QINTEGERPARAMETER_H

#include <qparameter.h>
#include <QDebug>

class QIntegerParameter : public QParameter
{
public:
    QIntegerParameter(QString name, int value, QObject *parent = 0);

    virtual const QString valueString();
    virtual void setValue(const QString value);
    void setValue(int value);
    virtual int type();

private:
    int _value;

};

#endif // QINTEGERPARAMETER_H
