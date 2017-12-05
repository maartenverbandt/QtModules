#include "qcommandportwidget.h"

QCommandPortWidget::QCommandPortWidget(QWidget *parent) :
    QWidget(parent)
{
    _layout = new QHBoxLayout();
    _button_layout = new QVBoxLayout();
    _button_layout->addStretch();
    _buttons = new QButtonGroup(this);
    _buttons->setExclusive(true);

    _controls_layout = new QHBoxLayout();
    QPushButton* start = new QPushButton("start");
    start->setCheckable(true);
    connect(start,&QPushButton::toggled,this,&QCommandPortWidget::startToggled);
    QPushButton* reset = new QPushButton("reset");
    connect(reset,&QPushButton::clicked,this,&QCommandPortWidget::reset);
    _controls_layout->addWidget(start);
    _controls_layout->addWidget(reset);

    _content_layout = new QVBoxLayout();
    _stack = new QStackedWidget();
    _content_layout->addWidget(_stack,1);
    _content_layout->addLayout(_controls_layout);

    setLayout(_layout);
    _layout->addLayout(_button_layout);
    _layout->addLayout(_content_layout);

    QObject::connect(_buttons,SIGNAL(buttonToggled(int,bool)),_stack,SLOT(setCurrentIndex(int)));
}

void QCommandPortWidget::setCurrentInputWidget(int index)
{
    if(index<_stack->count()){
        _buttons->button(index)->setChecked(true);
    }
}

void QCommandPortWidget::addInputWidget(QInputWidget *w)
{
    _ports.append(w);
    QPushButton* button = new QPushButton(w->objectName(),this);
    button->setMinimumSize(80,80);
    button->setMaximumSize(80,80);
    button->setCheckable(true);
    _button_layout->insertWidget(_button_layout->count()-1,button);
    _button_layout->setAlignment(button,Qt::AlignTop);

    _buttons->addButton(button,_stack->count());
    _stack->addWidget(w);
    setCurrentInputWidget(_stack->count()-1);
}

QInputWidget *QCommandPortWidget::currentInputWidget()
{
    return _ports.value(_stack->currentIndex());
}

void QCommandPortWidget::timerEvent(QTimerEvent *)
{
    currentInputWidget()->transmit();
}

void QCommandPortWidget::startToggled(bool checked)
{
    if(checked){
        start();
    } else {
        stop();
    }
}

void QCommandPortWidget::start()
{
    _timer_id = startTimer(50,Qt::PreciseTimer);
}

void QCommandPortWidget::stop()
{
    killTimer(_timer_id);
}

void QCommandPortWidget::reset()
{
    currentInputWidget()->reset();
}


