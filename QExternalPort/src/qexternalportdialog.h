#ifndef QEXTERNALPORTDIALOG_H
#define QEXTERNALPORTDIALOG_H

#include <QDialog>
#include <QLayout>
#include <QPushButton>
#include <QButtonGroup>
#include <QStackedWidget>
#include <QAction>
#include <qinputwidget.h>

class QExternalPortDialog : public QDialog
{
    Q_OBJECT
public:
    explicit QExternalPortDialog(QString name, QWidget *parent = 0);
    ~QExternalPortDialog();

    void addInputWidget(QInputWidget *w);
    QInputWidget* currentInputWidget();
    QInputWidget *findInputWidget(QString name);
    void setCurrentInputWidget(int index);

    QAction* getPopupAction();

protected:
    void timerEvent(QTimerEvent *);

private:
    QList<QInputWidget*> _ports;

    QAction* _popup;
    int _timer_id;

    QHBoxLayout* _layout;
    QHBoxLayout* _controls_layout;
    QVBoxLayout* _button_layout;
    QVBoxLayout* _content_layout;
    QButtonGroup* _buttons;
    QStackedWidget* _stack;

    void layoutSetup();

public slots:
    void startToggled(bool checked);
    void start();
    void stop();
    void reset();

signals:
    void commands(QList<QVariant> l);

};

#endif // QEXTERNALPORTDIALOG_H
