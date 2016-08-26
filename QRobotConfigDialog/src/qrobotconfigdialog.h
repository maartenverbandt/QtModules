#ifndef QROBOTCONFIGDIALOG_H
#define QROBOTCONFIGDIALOG_H

#include <QDebug>
#include <QDialog>
#include <QFileDialog>
#include <QTreeWidget>
#include <qtreewidgetparameter.h>

namespace Ui {
class QRobotConfigDialog;
}

class QRobotConfigDialog : public QDialog
{
    Q_OBJECT

public:
    explicit QRobotConfigDialog(QString name, QWidget *parent = 0);
    ~QRobotConfigDialog();

    virtual QByteArray getByteArray() = 0;
    virtual void fromByteArray(const QByteArray &data) = 0;

    void setExpanded(bool expand = true);
    QAction *getPopupAction();

protected:
    Ui::QRobotConfigDialog *ui;

    void addGroup(QString group);
    void addParameter(QTreeWidgetItem *item, QString group = QString());
    template <typename T> void addParameter(QString name, T *value, QString group = QString());

    void updateWidgets();
    void updateParameters();

    QList<QTreeWidgetParameterInterface*> _parameters;

private:
    QAction *_popup;

protected slots:
    void closeEvent(QCloseEvent *);

private slots:
    void on_save_pushButton_clicked();
    void on_open_pushButton_clicked();
    void on_load_pushButton_clicked();
    void on_send_pushButton_clicked();

    void popup();

signals:
    void readRobotSettings();
    void writeRobotSettings(QByteArray data);

};

template <typename T> void QRobotConfigDialog::addParameter(QString name, T *value, QString group)
{
    QTreeWidgetParameter<T>* item = new QTreeWidgetParameter<T>(name,value);
    _parameters.append(item);
    addParameter(item,group);
    item->setup();
}


#endif // QROBOTCONFIGDIALOG_H
