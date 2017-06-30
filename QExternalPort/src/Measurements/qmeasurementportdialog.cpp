#include "qmeasurementportdialog.h"

QMeasurementPortDialog::QMeasurementPortDialog(QString name, QWidget *parent) :
    QDialog(parent),
    _popup(new QAction(name,this))
{
    layoutSetup();
    QObject::connect(_popup,SIGNAL(triggered()),this,SLOT(show()));
    setWindowTitle(name);
}

QMeasurementPortDialog::~QMeasurementPortDialog()
{
    delete _stack;
}

void QMeasurementPortDialog::setCurrentOutputWidget(int index)
{
    if(index<_stack->count()){
        _buttons->button(index)->setChecked(true);
    }
}

void QMeasurementPortDialog::addOutputWidget(QOutputWidget *w)
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
    setCurrentOutputWidget(_stack->count()-1);
}

QOutputWidget *QMeasurementPortDialog::currentOutputWidget()
{
    return _ports.value(_stack->currentIndex());
}

QOutputWidget *QMeasurementPortDialog::findOutputWidget(QString name)
{
    for(int i=0; i<_ports.size(); i++){
        if(_ports[i]->objectName() == name)
            return _ports[i];
    }
    return NULL;
}

QAction *QMeasurementPortDialog::getPopupAction()
{
    return _popup;
}

void QMeasurementPortDialog::layoutSetup()
{
    _layout = new QHBoxLayout();
    _button_layout = new QVBoxLayout();
    _button_layout->addStretch();
    _buttons = new QButtonGroup(this);
    _buttons->setExclusive(true);

    _controls_layout = new QHBoxLayout();
    _start = new QPushButton("start");
    _start->setCheckable(true);
    QPushButton* reset = new QPushButton("reset");
    connect(reset,&QPushButton::clicked,this,&QMeasurementPortDialog::reset);
    _controls_layout->addWidget(_start);
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

void QMeasurementPortDialog::measurement(QVariant m)
{
    if(_start->isChecked()){
        QListIterator<QOutputWidget*> i(_ports);
        while(i.hasNext())
            i.next()->setPacket(m);
    }
}

void QMeasurementPortDialog::measurements(QList<QVariant> l)
{
    if(_start->isChecked()){
        QListIterator<QOutputWidget*> i(_ports);
        while(i.hasNext())
            i.next()->setPackets(l);
    }
}

void QMeasurementPortDialog::reset()
{
    currentOutputWidget()->reset();
}

