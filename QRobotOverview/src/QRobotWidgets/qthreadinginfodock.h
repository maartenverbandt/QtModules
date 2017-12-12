#ifndef QSHOWTHREADINGINFOACTION_H
#define QSHOWTHREADINGINFOACTION_H

#include <qshowdockaction.h>
#include <qthreadinfodatanodewidget.h>

class QShowThreadingInfoAction : public QShowDockAction
{
public:
    explicit QShowThreadingInfoAction(QRobotWindow *window, QObject *parent = 0);

protected:
    virtual void showDock();

};

#endif // QSHOWTHREADINGINFOACTION_H
