#ifndef QPARAMETERMANAGER_H
#define QPARAMETERMANAGER_H

#include <qdatanode.h>
#include <qparameter.h>
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
    void parameterAdded(QString name);
    void parameterChanged(QString name, QString value);

protected slots:
    /*virtual void transmit(mavlink_event_t);
    virtual void transmit(mavlink_param_int_t);
    virtual void transmit(mavlink_param_float_t);*/

    virtual void receive(mavlink_event_t event);
    virtual void receive(mavlink_param_int_t param_int);
    virtual void receive(mavlink_param_float_t param_float);

public slots:
    void updateParameter(QString name, QString value);

};

#endif // QPARAMETERMANAGER_H
