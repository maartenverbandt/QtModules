#ifndef QSHOWCOMMANDWIDGETACTION_H
#define QSHOWCOMMANDWIDGETACTION_H

#include <qshowdockaction.h>
#include <qcommandwidget.h>

class QShowCommandWidgetAction : public QShowDockAction
{
    Q_OBJECT
public:
    explicit QShowCommandWidgetAction(QRobotWindow *window, QObject *parent = 0);

protected:
    virtual void showDock();

};

#endif // QSHOWCOMMANDWIDGETACTION_H
