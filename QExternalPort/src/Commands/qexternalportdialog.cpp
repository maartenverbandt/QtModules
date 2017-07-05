#include "qexternalportdialog.h"

QExternalPortDialog::QExternalPortDialog(QString name, QWidget *parent) :
    QDialog(parent),
    _popup(new QAction(name,this))
{
    layoutSetup();
    QObject::connect(_popup,SIGNAL(triggered()),this,SLOT(show()));
    setWindowTitle(name);
}

QExternalPortDialog::~QExternalPortDialog()
{
    delete _stack;
}

void QExternalPortDialog::setCurrentInputWidget(int index)
{
    if(index<_stack->count()){
        _buttons->button(index)->setChecked(true);
    }
}

void QExternalPortDialog::addInputWidget(QInputWidget *w)
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

QInputWidget *QExternalPortDialog::currentInputWidget()
{
    return _ports.value(_stack->currentIndex());
}

QInputWidget *QExternalPortDialog::findInputWidget(QString name)
{
    for(int i=0; i<_ports.size(); i++){
        if(_ports[i]->objectName() == name)
            return _ports[i];
    }
    return NULL;
}

QAction *QExternalPortDialog::getPopupAction()
{
    return _popup;
}

void QExternalPortDialog::timerEvent(QTimerEvent *)
{
    emit commands(currentInputWidget()->read());
}

void QExternalPortDialog::layoutSetup()
{
    _layout = new QHBoxLayout();
    _button_layout = new QVBoxLayout();
    _button_layout->addStretch();
    _buttons = new QButtonGroup(this);
    _buttons->setExclusive(true);

    _controls_layout = new QHBoxLayout();
    QPushButton* start = new QPushButton("start");
    start->setCheckable(true);
    connect(start,&QPushButton::toggled,this,&QExternalPortDialog::startToggled);
    QPushButton* reset = new QPushButton("reset");
    connect(reset,&QPushButton::clicked,this,&QExternalPortDialog::reset);
    _controls_layout->addWidget(start);
    _controls_layout->addWidget(reset);

    _content_layout = new QVBoxLayout();
    _stack = new QStackedWidget(this);
    _content_layout->addWidget(_stack,1);
    _content_layout->addLayout(_controls_layout);

    setLayout(_layout);
    _layout->addLayout(_button_layout);
    _layout->addLayout(_content_layout);

    QObject::connect(_buttons,SIGNAL(buttonToggled(int,bool)),_stack,SLOT(setCurrentIndex(int)));
}

void QExternalPortDialog::startToggled(bool checked)
{
    if(checked){
        start();
    } else {
        stop();
    }
}

void QExternalPortDialog::start()
{
    _timer_id = startTimer(10,Qt::PreciseTimer);
}

void QExternalPortDialog::stop()
{
    killTimer(_timer_id);
}

void QExternalPortDialog::reset()
{
    currentInputWidget()->reset();
}


