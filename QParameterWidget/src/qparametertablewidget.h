#ifndef QPARAMETERTABLEWIDGET_H
#define QPARAMETERTABLEWIDGET_H

#include <QTableWidget>
#include <QHeaderView>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <qdebug.h>
#include <qparametermanager.h>

class QParameterTableWidget : public QWidget
{
    Q_OBJECT

public:
    QParameterTableWidget(QParameterManager *manager, QWidget *parent = 0);

    int addParameter(QParameter *parameter);

private:
    QTableWidget *_table;
    QPushButton *_load;
    QPushButton *_send;
    QPushButton *_store;

    void setup();

public slots:
    void handleCellChanged(int row);
    void updateParameter(QString name, QString value);

signals:
    void parameterChanged(QString name, QString value);

};

#endif // QPARAMETERTABLEWIDGET_H
