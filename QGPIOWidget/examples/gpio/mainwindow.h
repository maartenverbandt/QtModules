#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qgpiodatanodewidget.h>
#include <qgpiosignalgenerator.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QGPIODataNodeWidget *gpio;
    QGPIOSignalGenerator *sig;
};

#endif // MAINWINDOW_H
