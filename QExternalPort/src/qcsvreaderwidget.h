#ifndef QCSVREADERWIDGET_H
#define QCSVREADERWIDGET_H

#include <QWidget>
#include <qcsvreader.h>
#include <qfileinfo.h>
#include <qfiledialog.h>

namespace Ui {
class QCsvReaderWidget;
}

class QCsvReaderWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QCsvReaderWidget(QWidget *parent = 0);
    ~QCsvReaderWidget();

    QCsvReader* getCsvReader();
    QList<double> readLine();

private slots:
    void on_pushButton_clicked();

private:
    Ui::QCsvReaderWidget *ui;
    QCsvReader* _csv_reader;

};

#endif // QCSVREADERWIDGET_H
