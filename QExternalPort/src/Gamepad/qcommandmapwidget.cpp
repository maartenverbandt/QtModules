#include "qcommandmapwidget.h"
#include "ui_qcommandmapwidget.h"

QCommandMapWidget::QCommandMapWidget(QString name, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QCommandMapWidget)
{
    ui->setupUi(this);
    ui->groupBox->setTitle(name);
}

QCommandMapWidget::~QCommandMapWidget()
{
    delete ui;
}

bool QCommandMapWidget::enabled()
{
    return ui->groupBox->isChecked();
}

void QCommandMapWidget::add(QString name)
{
    QCommand *command = new QCommand(name,0);
    add(command);
}

void QCommandMapWidget::add(QCommand *command)
{
    _map.insert(command->objectName(), command);
    ui->layout->addWidget(command);
}

double QCommandMapWidget::value(QString command)
{
    return _map[command]->value();
}

bool QCommandMapWidget::setValue(QGamepadButton button)
{
    QList<QCommand*> commands = _map.values();
    for(int i=0; i<commands.size(); i++){
        if(commands[i]->button()->buttonID() == button.buttonID()){
            commands[i]->button()->setValue(button.value());
            return true;
        }
    }
    return false;
}

void QCommandMapWidget::setup()
{

}

void QCommandMapWidget::masterDeviceChanged(int device_id)
{
    QList<QCommand*> commands = _map.values();
    QListIterator<QCommand*> i(commands);
    while(i.hasNext())
        i.next()->masterDeviceChanged(device_id);
}

/*void QCommandMapWidget::add(QString command)
{
    QCommandMap::add(command);

}*/

/*QGamepadButton *QCommandMapWidget::button(QString name)
{
    for (int i=0; i<_buttons.size(); i++){
        if(_buttons[i]->objectName() == name)
            return _buttons[i];
    }
    return NULL;
}*/



/*void QCommandMapWidget::setup()
{
    QList<QString> buttonnames = QGamepadButton::axisNames();
    buttonnames.append(QGamepadButton::buttonNames());
    QList<int> buttonids = QGamepadButton::axisIDs();
    buttonids.append(QGamepadButton::buttonIDs());

    for (int i = 0; i<commands().size(); i++) {
        QString command = commands()[i];
        QComboBox *select = new QComboBox();
        for(int j = 0; j<buttonnames.size(); j++){
            select->addItem(buttonnames[i],QVariant(buttonids[i]));
        }
        _boxmapper->setMapping(select,i);
        QObject::connect(select,SIGNAL(currentIndexChanged(int)),_boxmapper,SLOT(map()));
        ui->formLayout->addRow(command,select);
        _boxes.append(select);
    }
    QObject::connect(_boxmapper,SIGNAL(mapped(int)),this,SLOT(boxChanged(int)));
}*/

/*void QCommandMapWidget::boxChanged(int id)
{
    //map(commands()[id], _buttons[_boxes[id]->currentIndex()]);
}*/
