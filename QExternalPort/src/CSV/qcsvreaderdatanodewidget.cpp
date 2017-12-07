#include "qcsvreaderdatanodewidget.h"

QCsvReaderDataNodeWidget::QCsvReaderDataNodeWidget(const QString& name, QWidget *parent) :
    QDataPortInterface(parent), _csv_reader(new QCsvReaderWidget(name, parent))
{

}

QWidget *QCsvReaderDataNodeWidget::w()
{
    return _csv_reader;
}

bool QCsvReaderDataNodeWidget::enabled()
{
    return _csv_reader->enabled();
}

void QCsvReaderDataNodeWidget::reset()
{
    _csv_reader->getCsvReader()->reset();
}
