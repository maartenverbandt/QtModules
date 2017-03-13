#include "qcommandmapwidget.h"
#include "ui_qgamepadcommandwidget.h"

QCommandMapWidget::QCommandMapWidget(QGamepadInputWidget *parent) :
    QWidget(parent),
    ui(new Ui::QGamepadCommandWidget),
    _boxmapper(new QSignalMapper(this))
{
    ui->setupUi(this);

    // setup buttons
    _buttons = parent->gamepad()->buttons();
}

QCommandMapWidget::~QCommandMapWidget()
{
    delete ui;
}

bool QCommandMapWidget::enabled()
{
    return ui->groupBox->isChecked();
}

QGamepadButton *QCommandMapWidget::button(QString name)
{
    for (int i=0; i<_buttons.size(); i++){
        if(_buttons[i]->objectName() == name)
            return _buttons[i];
    }
    return NULL;
}

void QCommandMapWidget::setup()
{
    QList<QString> buttonnames;
    for (int i = 0; i<_buttons.size(); i++) {
        buttonnames.append(_buttons[i]->objectName());
    }

    for (int i = 0; i<commands().size(); i++) {
        QString command = commands()[i];
        QComboBox *box = new QComboBox();
        box->addItems(buttonnames);
        _boxmapper->setMapping(box,i);
        QObject::connect(box,SIGNAL(currentIndexChanged(int)),_boxmapper,SLOT(map()));
        ui->formLayout->addRow(command,box);
        _boxes.append(box);
    }
    QObject::connect(_boxmapper,SIGNAL(mapped(int)),this,SLOT(boxChanged(int)));
}

void QCommandMapWidget::boxChanged(int id)
{
    map(commands()[id], _buttons[_boxes[id]->currentIndex()]);
}
