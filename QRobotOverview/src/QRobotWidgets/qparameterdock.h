#ifndef QPARAMETERDOCK_H
#define QPARAMETERDOCK_H

#include <qrobotwindowdock.h>
#include <qparameterdatanodewidget.h>

class QParameterDock : public QRobotWindowDock
{
    Q_OBJECT
public:
    explicit QParameterDock(QRobotWindow *window);
    QParameterDataNodeWidget *datanode();

private:
    QParameterDataNodeWidget *_parameter_datanode_widget;

protected slots:
    //virtual void on_show_widget();

};

#endif // QPARAMETERDOCK_H
