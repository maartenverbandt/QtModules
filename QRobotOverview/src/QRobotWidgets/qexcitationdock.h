#ifndef QSHOWEXCITATIONWINDOWACTION_H
#define QSHOWEXCITATIONWINDOWACTION_H

#include <qshowdockaction.h>
#include <qexcitationwidget.h>

class QShowExcitationWindowAction : public QShowDockAction
{
    Q_OBJECT
public:
    explicit QShowExcitationWindowAction(QRobotWindow *window, QObject *parent = 0);

    virtual void showDock();
};

#endif // QSHOWEXCITATIONWINDOWACTION_H
