#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    //QPositionCmdPortDialog* d = new QPositionCmdPortDialog(0);
    //d->show();

    //QObject::connect(d,SIGNAL(positionCmdPacket(mavlink_position_cmd_t)),&w,SLOT(positionCmdCatch(mavlink_position_cmd_t)));

    return a.exec();
}
