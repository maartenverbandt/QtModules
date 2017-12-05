#include "qshowexcitationwindowaction.h"

QShowExcitationWindowAction::QShowExcitationWindowAction(QRobotWindow *window, QObject *parent) :
    QShowDockAction("excitation", window, parent)
{
    //do nothing
}

void QShowExcitationWindowAction::showDock()
{
    QDockWidget *dock = new QDockWidget("excitation", _window);
    QExcitationWidget *w = new QExcitationWidget(dock);

    QListIterator<QSerialProtocol *> i(_window->robot()->connections());
    while(i.hasNext())
        w->transmitTo(i.next());

    dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    dock->setWidget(w);
    _window->addDockWidget(Qt::RightDockWidgetArea, dock);
}
