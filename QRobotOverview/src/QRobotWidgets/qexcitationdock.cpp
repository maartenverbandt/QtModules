#include "qexcitationdock.h"

QExcitationDock::QExcitationDock(QRobotWindow *window) :
    QRobotWindowDock("excitation", window), _excitation_widget(new QExcitationWidget(this))
{
    QListIterator<QSerialProtocol *> i(window->robot()->connections());
    while(i.hasNext())
        _excitation_widget->transmitTo(i.next());

    setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    setWidget(_excitation_widget);
    window->addDockWidget(Qt::RightDockWidgetArea, this);
    //restoreState();
}
