#include "qabstractrobot.h"

QAbstractRobot::QAbstractRobot(const int id, const QString type, QObject *parent) :
    QObject(parent),
    _id(id),
    _type(type),
    _log(new QPrintLog(this))
{
    setObjectName(_type + QString::number(_id));
}

/*void QAbstractRobot::setup()
{
    //setup robot log
    _log->open(getName());
    QObject::connect(getConnectionManager(),&QRobotConnectionManager::printReceived,_log,&QRobotLog::write);
    //setup window
    getWindow()->setWindowTitle(getName());
    getWindow()->setWindowIcon(getIcon());
    //restore state
    restoreState();
}*/

int QAbstractRobot::id()
{
    return _id;
}

QString QAbstractRobot::type()
{
    return _type;
}

QList<QSerialProtocol *> QAbstractRobot::connections()
{
    return _connections;
}

void QAbstractRobot::connectTo(QDataNode *datanode)
{
    QListIterator<QSerialProtocol*> i(_connections);
    while(i.hasNext())
        i.next()->connectTo(datanode);
}

void QAbstractRobot::addConnection(QSerialProtocol *connection)
{
    _connections.append(connection);
    window()->handleNewConnection(connection);
    //connect what needs to be connected!
}

QPrintLog *QAbstractRobot::getLog()
{
    return _log;
}

/*void QAbstractRobot::saveState()
{
    getWindow()->saveState(getName());
}

void QAbstractRobot::restoreState()
{
    getWindow()->restoreState(getName());
}*/
