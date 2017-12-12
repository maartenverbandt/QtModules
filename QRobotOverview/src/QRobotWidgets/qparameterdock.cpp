#include "qparameterdock.h"

QParameterDock::QParameterDock(QRobotWindow *window) :
    QRobotWindowDock("parameters", window),
    _parameter_datanode_widget(new QParameterDataNodeWidget(this))
{
    setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    setWidget(_parameter_datanode_widget->w());
    window->addDockWidget(Qt::RightDockWidgetArea, this);

}

QParameterDataNodeWidget *QParameterDock::dataNode()
{
    return _parameter_datanode_widget;
}

/*void QShowParameterWidgetAction::on_show_widget()
{
    _parameter_datanode_widget->parameterTableWidget()->load()->click();
}*/
