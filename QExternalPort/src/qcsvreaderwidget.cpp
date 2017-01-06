#include "qcsvreaderwidget.h"
#include "ui_qcsvreaderwidget.h"

QCsvReaderWidget::QCsvReaderWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QCsvReaderWidget),
    _csv_reader(new QCsvReader(this))
{
    ui->setupUi(this);
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
    ui->progressBar->setValue(100.0*_csv_reader->progress());
    return values;
}

void QCsvReaderWidget::on_pushButton_clicked()
{
    QFileInfo info(*(_csv_reader->getFile()));
    QString path = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                    info.path(),
                                                    tr("CSV files (*.csv *.txt)"));
    if(~path.isEmpty()){
        if(_csv_reader->setFile(path)){
            QFileInfo info(*(_csv_reader->getFile()));
            ui->label->setText(info.fileName());
        }
    }
}
