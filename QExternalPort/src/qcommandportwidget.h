#ifndef QCOMMANDPORTWIDGET_H
#define QCOMMANDPORTWIDGET_H

#include <QDialog>
#include <QLayout>
#include <QPushButton>
#include <QButtonGroup>
#include <QStackedWidget>
#include <QAction>
#include <qinputwidget.h>

class QCommandPortWidget : public QWidget
{
    Q_OBJECT
public:
    explicit QCommandPortWidget(QWidget *parent = 0);

    void addInputWidget(QInputWidget *w);
    QInputWidget *currentInputWidget();
    void setCurrentInputWidget(int index);

protected:
    void timerEvent(QTimerEvent *);

private:
    QList<QInputWidget*> _ports;

    int _timer_id;

    QHBoxLayout* _layout;
    QHBoxLayout* _controls_layout;
    QVBoxLayout* _button_layout;
    QVBoxLayout* _content_layout;
    QButtonGroup* _buttons;
    QStackedWidget* _stack;

    void setup();

public slots:
    void startToggled(bool checked);
    void start();
    void stop();
    void reset();

};

#endif // QCOMMANDPORTWIDGET_H
