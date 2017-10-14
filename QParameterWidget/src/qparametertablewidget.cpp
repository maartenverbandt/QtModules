#include "qparametertablewidget.h"

QParameterTableWidget::QParameterTableWidget(QParameterManager *manager, QWidget *parent) :
    QWidget(parent),
    _table(new QTableWidget(this)),
    _load(new QPushButton("load",this)),
    _send(new QPushButton("send",this)),
    _store(new QPushButton("store",this))
{
    setup();

    QListIterator<QParameter*> i(manager->parameters());
    while(i.hasNext())
        addParameter(i.next());

    QObject::connect(manager, &QParameterManager::parameterChanged, this, &QParameterTableWidget::updateParameter);
    QObject::connect(this, &QParameterTableWidget::parameterChanged, manager, &QParameterManager::updateParameter);
}

int QParameterTableWidget::addParameter(QParameter *parameter)
{
    _table->insertRow(_table->rowCount());
    QTableWidgetItem *name = new QTableWidgetItem(parameter->name());
    QTableWidgetItem *value = new QTableWidgetItem(parameter->valueString());
    value->setTextAlignment(Qt::AlignRight);
    _table->setItem(_table->rowCount()-1,0,name);
    _table->setItem(_table->rowCount()-1,1,value);

    return (_table->rowCount()-1);
}

void QParameterTableWidget::setup()
{
    _table->setColumnCount(2);
    _table->setRowCount(0);
    _table->setHorizontalHeaderLabels(QStringList({"name","value"}));

    QHeaderView* header = _table->horizontalHeader();
    header->setSectionResizeMode(QHeaderView::Stretch);

    QHBoxLayout *lh = new QHBoxLayout();
    lh->addWidget(_load);
    lh->addWidget(_send);
    lh->addWidget(_store);

    QVBoxLayout *lv = new QVBoxLayout(this);
    setLayout(lv);
    lv->addWidget(_table);
    lv->addLayout(lh);
}

void QParameterTableWidget::handleCellChanged(int row)
{
    QString name = _table->item(row,0)->text();
    QString value = _table->item(row,1)->text();
    emit parameterChanged(name, value);
}

void QParameterTableWidget::updateParameter(QString name, QString value)
{
    // Find item based on name
    QList<QTableWidgetItem*> list = _table->findItems(name, Qt::MatchExactly);
    for(int k=(list.size()-1); k>=0; k--){
        if(_table->column(list[k]) != 0) {
            list.removeAt(k);
        }
    }

    // Change the corresponding value
    if(list.size() == 1) {
        int row = _table->row(list[0]);
        _table->itemAt(row, 1)->setText(value);
    } else {
        qWarning() << "More than one parameter found! Implementation error it seems.";
    }
}
