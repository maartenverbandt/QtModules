#ifndef QSHOWPARAMETERWIDGETACTION_H
#define QSHOWPARAMETERWIDGETACTION_H

#include <qshowdockaction.h>
#include <qparameterdatanodewidget.h>

class QShowParameterWidgetAction : public QShowDockAction
{
    Q_OBJECT
public:
    explicit QShowParameterWidgetAction(QRobotWindow *window, QObject *parent = 0);

protected:
    virtual void showDock();

};

#endif // QSHOWPARAMETERWIDGETACTION_H
