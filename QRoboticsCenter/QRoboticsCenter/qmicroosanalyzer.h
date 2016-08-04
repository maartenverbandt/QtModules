#ifndef QMICROOSANALYZER_H
#define QMICROOSANALYZER_H

#include <QMainWindow>
#include <qconnectioncoordinator.h>
#include <qgpiowidget.h>
#include <qthreadingwidget.h>
#include <qloggerdialog.h>

namespace Ui {
class QMicroOSAnalyzer;
}

class QMicroOSAnalyzer : public QMainWindow
{
    Q_OBJECT

public:
    explicit QMicroOSAnalyzer(QWidget *parent = 0);
    ~QMicroOSAnalyzer();

private:
    Ui::QMicroOSAnalyzer *ui;
    QConnectionCoordinator *coordinator;

private slots:
    void handleMavlinkConnectionFound(QMavlinkConnection *mavlink_connection);
    void search();
    void launchThreadsDialog();
    void launchDebugDialog();
    void launchMessagesDialog();
    void launchLoggerDialog();
};

#endif // QMICROOSANALYZER_H
