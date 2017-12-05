#ifndef QABSTRACTROBOT_H
#define QABSTRACTROBOT_H

#include <QObject>
#include <QIcon>
#include <qdatanode.h>
#include <qrobotwindow.h>
#include <qprintlog.h>
/*#include <qrobotconnectionmanager.h>
#include <qrobotrecordermanager.h>
#include <qrobotcommandmanager.h>
#include <qrobotmeasurementmanager.h>*/

class QRobotWindow;

class QAbstractRobot : public QObject
{
    Q_OBJECT

public:
    explicit QAbstractRobot(const int id, const QString type, QObject *parent = 0);

    virtual QIcon icon() = 0;
    virtual QRobotWindow *window() = 0;

    /*virtual void setup();
    virtual QRobotConnectionManager* getConnectionManager() = 0;
    virtual QRobotRecorderManager* getRecorderManager() = 0;
    virtual QRobotCommandManager* getCommandManager() = 0;
    virtual QRobotMeasurementManager* getMeasurementManager() = 0;*/

    int id();
    QString type();
    QList<QSerialProtocol *> connections();
    QPrintLog *getLog();

    //virtual void saveState();
    //virtual void restoreState();

    void connectTo(QDataNode *datanode);

private:
    const int _id;
    const QString _type;
    QList<QSerialProtocol*> _connections;
    QPrintLog* _log;

public slots:
    void addConnection(QSerialProtocol *connection);

};

#endif // QABSTRACTROBOT_H