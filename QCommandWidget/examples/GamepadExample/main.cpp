#include <QApplication>
#include <qgamepadcommandwidget.h>
#include <qvelocitygamepadcommand.h>
#include <qcommandwidget.h>
#include <listener.h>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QCoreApplication::setOrganizationName("RobSoft");
    QCoreApplication::setApplicationName("GamepadExample");
    
    QGamepadCommandWidget *gamepad = new QGamepadCommandWidget("Gamepad");
    gamepad->add(new QVelocityGamepadCommand(gamepad));

    QCommandWidget *d = new QCommandWidget(0);
    d->add(gamepad);
    d->show();

    Listener *l = new Listener(0);
    d->transmitTo(l);

    d->restoreState("gamepad_test");
    QObject::connect(&a,&QApplication::aboutToQuit,[=](){d->saveState("gamepad_test");});

    return a.exec();
}
