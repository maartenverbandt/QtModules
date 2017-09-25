#include "qcsvreaderwidget.h"
#include "ui_qcsvreaderwidget.h"
#include <QSettings>

QCsvReaderWidget::QCsvReaderWidget(QString name, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QCsvReaderWidget),
    _csv_reader(new QCsvReader(this))
{
    ui->setupUi(this);
    ui->groupBox->setTitle(name);
}

QCsvReaderWidget::~QCsvReaderWidget()
{
    delete ui;
}

QCsvReader *QCsvReaderWidget::getCsvReader()
{
    return _csv_reader;
}

QList<double> QCsvReaderWidget::readLine()
{
    QList<double> values = _csv_reader->readLine();
    updateProgressBar();
    return values;
}

bool QCsvReaderWidget::enabled()
{
    return ui->groupBox->isChecked();
}

void QCsvReaderWidget::reset()
{
    _csv_reader->reset();
    updateFileName();
    updateProgressBar();
}

void QCsvReaderWidget::saveState(QString group)
{
    QSettings settings;

    settings.beginGroup(group);
    settings.setValue("filename", QVariant(_csv_reader->fileName()));
    settings.endGroup();
}

void QCsvReaderWidget::restoreState(QString group)
{
    QSettings settings;

    settings.beginGroup(group);
    if(!_csv_reader->setFile(settings.value("filename").toString())) {
        qWarning() << "Unable to restore" << settings.value("filename").toString();
    } else {
        updateFileName();
    }
    settings.endGroup();
}

void QCsvReaderWidget::updateFileName()
{
    ui->label->setText(_csv_reader->fileName());
}

void QCsvReaderWidget::updateProgressBar()
{
    ui->progressBar->setValue(100.0*_csv_reader->progress());
}

void QCsvReaderWidget::on_pushButton_clicked()
{
    QFileInfo info(*(_csv_reader->getFile()));
    QString path = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                    info.path(),
                                                    tr("CSV files (*.csv *.txt)"));
    if(~path.isEmpty()){
        if(_csv_reader->setFile(path)){
            updateFileName();
        }
    }
}
