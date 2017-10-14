#ifndef QSTRINGPARAMETER_H
#define QSTRINGPARAMETER_H

#include <qparameter.h>
#include <QDebug>

class QStringParameter : public QParameter
{
public:
    QStringParameter(QString name, QString value, QObject *parent = 0);

    virtual const QString valueString();
    virtual void setValue(const QString value);
    virtual int type();

private:
    QString _value;

};

#endif // QSTRINGPARAMETER_H
