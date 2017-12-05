#ifndef QSHOWCONNECTIONINFOACTION_H
#define QSHOWCONNECTIONINFOACTION_H

#include <qshowdockaction.h>
#include <qconnectioninfodatanodewidget.h>

class QShowConnectionInfoAction : public QShowDockAction
{
public:
    explicit QShowConnectionInfoAction(QDataNode *connection, QRobotWindow *window, QObject *parent = 0);

private:
    QDataNode *_connection;

protected:
    virtual void showDock();

};

#endif // QSHOWCONNECTIONINFOACTION_H
