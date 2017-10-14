#ifndef QPARAMETER_H
#define QPARAMETER_H

#include <QObject>

class QParameter : public QObject
{
    Q_OBJECT
public:
    explicit QParameter(const QString name, QObject *parent = 0);

    const QString name();
    virtual const QString valueString() = 0;
    virtual void setValue(const QString value) = 0;
    virtual int type() = 0;

    enum type_t {
        INTEGER = 1001,
        FLOAT,
        STRING
    };

private:
    const QString _name;

signals:

public slots:
};

#endif // QPARAMETER_H
