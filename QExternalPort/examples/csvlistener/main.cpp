#include <QApplication>
#include <qinputwidget.h>
#include <qgpiocsvreader.h>
#include <qpositioncmdcsvreader.h>
#include <qtudpreader.h>
#include <qgamepadinputwidget.h>
#include <qcommandportwidget.h>
#include <qvelocitygamepadcommand.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();

    //QPositionCmdPortDialog* d = new QPositionCmdPortDialog(0);
    //d->show();

    //QObject::connect(d,SIGNAL(positionCmdPacket(mavlink_position_cmd_t)),&w,SLOT(positionCmdCatch(mavlink_position_cmd_t)));

    QInputWidget *inputwidget = new QInputWidget("CSV");
    inputwidget->addPort(new QGpioCsvReader(0));
    inputwidget->addPort(new QPositionCmdCsvReader(0));

    QInputWidget *inputwidgetUDP = new QInputWidget("UDP");
    inputwidgetUDP->addPort(new QGpioUdpReader(0));
    inputwidgetUDP->addPort(new QPositionCmdUdpReader(0));

    QGamepadInputWidget *gpinput = new QGamepadInputWidget("gamepad");
    gpinput->addPort(new QVelocityGamepadCommand());

    QCommandPortWidget *command = new QCommandPortWidget(0);
    command->addInputWidget(inputwidget);
    command->addInputWidget(inputwidgetUDP);
    command->addInputWidget(gpinput);
    command->show();

    return a.exec();
}
