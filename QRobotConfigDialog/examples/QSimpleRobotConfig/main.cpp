#include <QApplication>
#include <qsimplerobotconfig.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSimpleRobotConfig *dialog = new QSimpleRobotConfig();
    dialog->exec();

    return a.exec();
}
