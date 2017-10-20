#include "qparametertablewidget.h"

QParameterTableWidget::QParameterTableWidget(QParameterManager *manager, QWidget *parent) :
    QWidget(parent),
    _table(new QTableWidget(this)),
    _load(new QPushButton("load",this)),
    _send(new QPushButton("send",this)),
    _store(new QPushButton("store",this))
{
    setup();

    QList<QParameter*> list = manager->parameters();
    for(int k=0; k<list.size(); k++) {
        addParameter(list[k]->name(), list[k]->valueString());
    }

    QObject::connect(_table, &QTableWidget::cellChanged, this, &QParameterTableWidget::handleCellChanged);

    QObject::connect(manager, &QParameterManager::parameterAdded, this, &QParameterTableWidget::addParameter);
    QObject::connect(manager, &QParameterManager::parameterChanged, this, &QParameterTableWidget::updateParameter);
    QObject::connect(this, &QParameterTableWidget::parameterChanged, manager, &QParameterManager::updateParameter);
    QObject::connect(_send, &QPushButton::clicked, manager, &QParameterManager::transmitParameters);
    QObject::connect(_load, &QPushButton::clicked, manager, &QParameterManager::requestParameters);
    QObject::connect(_store, &QPushButton::clicked, manager, &QParameterManager::storeParameters);
}

int QParameterTableWidget::addParameter(QString name, QString value)
{
    _table->insertRow(_table->rowCount());
    QTableWidgetItem *name_item = new QTableWidgetItem(name);
    QTableWidgetItem *value_item = new QTableWidgetItem(value);
    value_item->setTextAlignment(Qt::AlignRight);
    _table->setItem(_table->rowCount()-1,0,name_item);
    _table->setItem(_table->rowCount()-1,1,value_item);

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

void QParameterTableWidget::handleCellChanged(int row, int column)
{
    if(column==1) {
        QString name = _table->item(row,0)->text();
        QString value = _table->item(row,1)->text();
        emit parameterChanged(name, value);
    }
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
        _table->item(row,1)->setText(value);
    } else {
        qWarning() << "More than one parameter found! Implementation error it seems.";
    }
}
