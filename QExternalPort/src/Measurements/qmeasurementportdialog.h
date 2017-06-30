#ifndef QMEASUREMENTPORTDIALOG_H
#define QMEASUREMENTPORTDIALOG_H

#include <QDialog>
#include <QLayout>
#include <QPushButton>
#include <QButtonGroup>
#include <QStackedWidget>
#include <QAction>
#include <qoutputwidget.h>

class QMeasurementPortDialog : public QDialog
{
    Q_OBJECT
public:
    explicit QMeasurementPortDialog(QString name, QWidget *parent = 0);
    ~QMeasurementPortDialog();

    void addOutputWidget(QOutputWidget *w);
    QOutputWidget* currentOutputWidget();
    QOutputWidget *findOutputWidget(QString name);
    void setCurrentOutputWidget(int index);

    QAction* getPopupAction();

private:
    QList<QOutputWidget*> _ports;

    QAction* _popup;

    QHBoxLayout* _layout;
    QHBoxLayout* _controls_layout;
    QVBoxLayout* _button_layout;
    QVBoxLayout* _content_layout;
    QButtonGroup* _buttons;
    QStackedWidget* _stack;
    QPushButton* _start;

    void layoutSetup();

public slots:
    void measurements(QList<QVariant> l);
    void reset();

};

#endif // QMEASUREMENTPORTDIALOG_H
