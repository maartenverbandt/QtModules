#ifndef QPARAMETERMANAGER_H
#define QPARAMETERMANAGER_H

#include <qdatanode.h>
#include <qparameter.h>
#include <qintegerparameter.h>
#include <qfloatparameter.h>
#include <qstringparameter.h>
#include <qdebug.h>

class QParameterManager : public QDataNode
{
    Q_OBJECT

public:
    QParameterManager(QObject *parent = 0);

    const QList<QParameter *> parameters();
    void addParameter(QParameter *parameter);

    bool hasParameter(const QString name);
    QParameter *findParameter(const QString name, bool *ok = Q_NULLPTR);

private:
    QMap<QString,QParameter*> _parameter_map;

signals:
    void parameterAdded(QString name, QString value);
    void parameterChanged(QString name, QString value);

    virtual void transmit(event_t event);
    virtual void transmit(param_int_t param_int);
    virtual void transmit(param_float_t param_float);

protected slots:
    virtual void receive(param_int_t param_int);
    virtual void receive(param_float_t param_float);

public slots:
    void updateParameter(QString name, QString value);
    void transmitParameters();
    void requestParameters();
    void storeParameters();

};

#endif // QPARAMETERMANAGER_H
