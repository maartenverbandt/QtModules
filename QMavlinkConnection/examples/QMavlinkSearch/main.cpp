#include <QApplication>
#include <qconnectioncoordinator.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QConnectionCoordinator coordinator;
    coordinator.query();

    return a.exec();
}
