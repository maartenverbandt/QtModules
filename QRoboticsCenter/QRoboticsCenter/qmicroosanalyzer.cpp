#include "qmicroosanalyzer.h"
#include "ui_qmicroosanalyzer.h"

QMicroOSAnalyzer::QMicroOSAnalyzer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QMicroOSAnalyzer),
    coordinator(new QConnectionCoordinator(this))
{
    ui->setupUi(this);

    QObject::connect(coordinator,SIGNAL(mavlinkConnectionFound(QMavlinkConnection*)),this,SLOT(handleMavlinkConnectionFound(QMavlinkConnection*)));
    QObject::connect(ui->searchButton,SIGNAL(released()),this,SLOT(search()));
    QObject::connect(ui->threadsButton,SIGNAL(released()),this,SLOT(launchThreadsDialog()));
    QObject::connect(ui->messagesButton,SIGNAL(released()),this,SLOT(launchMessagesDialog()));
    QObject::connect(ui->debugButton,SIGNAL(released()),this,SLOT(launchDebugDialog()));
    QObject::connect(ui->loggerButton,SIGNAL(released()),this,SLOT(launchLoggerDialog()));

    setAttribute(Qt::WA_DeleteOnClose);
    this->search();
}

QMicroOSAnalyzer::~QMicroOSAnalyzer()
{
    delete coordinator;
    delete ui;

}

void QMicroOSAnalyzer::handleMavlinkConnectionFound(QMavlinkConnection *mavlink_connection)
{
    ui->comboBox->addItem(mavlink_connection->name());
}

void QMicroOSAnalyzer::search()
{
    coordinator->scanUSB();
}

void QMicroOSAnalyzer::launchThreadsDialog()
{
    QMavlinkConnection* connection = coordinator->findMavlinkConnection(ui->comboBox->currentText());
    if(connection != NULL){
        QWidget* threadingDialog = new QThreadingWidget(0);
        threadingDialog->setWindowTitle(ui->comboBox->currentText() + " - Threading Dialog");
        QObject::connect(this,SIGNAL(destroyed(QObject*)),threadingDialog,SLOT(deleteLater()));
        QObject::connect(connection,SIGNAL(mavlinkMsgReceived(mavlink_message_t)),threadingDialog,SLOT(mavlinkMsgReceived(mavlink_message_t)));
    } else {
        qDebug() << "Connection not found in list";
    }
}

void QMicroOSAnalyzer::launchDebugDialog()
{
    QMavlinkConnection* connection = coordinator->findMavlinkConnection(ui->comboBox->currentText());
    if(connection != NULL){
        QWidget* debugDialog = new QGPIOWidget(0);
        debugDialog->setWindowTitle(ui->comboBox->currentText() + " - GPIO Dialog");
        QObject::connect(this,SIGNAL(destroyed(QObject*)),debugDialog,SLOT(deleteLater()));
        QObject::connect(connection,SIGNAL(mavlinkMsgReceived(mavlink_message_t)),debugDialog,SLOT(mavlinkMsgReceived(mavlink_message_t)));
        QObject::connect(debugDialog,SIGNAL(mavlinkMsgSend(mavlink_message_t)),connection,SLOT(mavlinkMsgSend(mavlink_message_t)));
    } else {
        qDebug() << "Connection not found in list";
    }
}

void QMicroOSAnalyzer::launchMessagesDialog()
{
    QMavlinkConnection* connection = coordinator->findMavlinkConnection(ui->comboBox->currentText());
    if(connection != NULL){
        connection->connectionInfoDialog();
    } else {
        qDebug() << "Connection not found in list";
    }
}

void QMicroOSAnalyzer::launchLoggerDialog()
{
    QMavlinkConnection* connection = coordinator->findMavlinkConnection(ui->comboBox->currentText());
    if(connection != NULL){
        QWidget* loggerDialog = new QLoggerDialog(0);
        loggerDialog->setWindowTitle(ui->comboBox->currentText() + " - Logger Dialog");
        QObject::connect(this,SIGNAL(destroyed(QObject*)),loggerDialog,SLOT(deleteLater()));
        QObject::connect(connection,SIGNAL(mavlinkMsgReceived(mavlink_message_t)),loggerDialog,SLOT(mavlinkMsgReceived(mavlink_message_t)));
    } else {
        qDebug() << "Connection not found in list";
    }
}
