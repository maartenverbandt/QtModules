#ifndef QINTEGERPARAMETER_H
#define QINTEGERPARAMETER_H

#include <qparameter.h>
#include <QDebug>

class QIntegerParameter : public QParameter
{
public:
    QIntegerParameter(QString name, int offset, int value, QObject *parent = 0);

    virtual const QString valueString();
    virtual void setValue(const QString value);
    virtual int type();

    void setValue(int value);
    int value();

private:
    int _value;

};

#endif // QINTEGERPARAMETER_H
