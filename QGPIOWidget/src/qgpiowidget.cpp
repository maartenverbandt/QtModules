#include "qgpiowidget.h"
#include "ui_qgpiowidget.h"

QGPIOWidget::QGPIOWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QGPIOWidget),
    double_list(QGPIOWIDGET_FLOAT_COUNT,0.0),
    integer_list(QGPIOWIDGET_INT_COUNT,0),
    _time(0),
    _paused(false)
{
    ui->setupUi(this);
    ui->plot->init(40,QGPIOWIDGET_IOCOUNT); //make graph with 12 functions

    grid_layout_spinbox = new QGridLayout(0);
    grid_layout_checkbox = new QGridLayout(0);
    grid_layout_buttons = new QGridLayout(0);
    QObject::connect(&buttons,SIGNAL(buttonClicked(int)),this,SLOT(sendButtonEvent(int)));

    int k;

    for(k = 0;k < 8;k++){
        // Outputs floats
        grid_layout_spinbox->addWidget(&spinboxlabels[k],k,0);
        grid_layout_spinbox->addWidget(&spinboxs[k],k,1);
        spinboxs[k].setRange(-1000000,1000000);
        spinboxs[k].setDecimals(4);

        // Label buttons
        buttons.addButton(new QPushButton("Button " + QString::number(k),this),k);
    }

    for(k = 0;k < 4;k++){
        // Outputs ints
        grid_layout_spinbox->addWidget(&spinboxlabels[k+QGPIOWIDGET_FLOAT_COUNT],k+QGPIOWIDGET_FLOAT_COUNT,0);
        grid_layout_spinbox->addWidget(&spinboxs[k+QGPIOWIDGET_FLOAT_COUNT],k+QGPIOWIDGET_FLOAT_COUNT,1);
        spinboxs[QGPIOWIDGET_FLOAT_COUNT+k].setRange(-1000000,1000000);
        spinboxs[QGPIOWIDGET_FLOAT_COUNT+k].setDecimals(0);

        // Layout buttons
        grid_layout_buttons->addWidget(buttons.button(2*k),k,0);
        grid_layout_buttons->addWidget(buttons.button(2*k+1),k,1);

        // Channels row 1 (floats)
        grid_layout_checkbox->addWidget(&checkboxlabels[k],0,2*k);
        grid_layout_checkbox->addWidget(&checkboxs[k],0,2*k+1);

        // Channels row 2 (floats)
        grid_layout_checkbox->addWidget(&checkboxlabels[k+4],1,2*k);
        grid_layout_checkbox->addWidget(&checkboxs[k+4],1,2*k+1);

        // Channels row 3 (ints)
        grid_layout_checkbox->addWidget(&checkboxlabels[k+8],2,2*k);
        grid_layout_checkbox->addWidget(&checkboxs[k+8],2,2*k+1);
    }

    for(k = 0;k < 12;k++){
        QPen pen = QPen(QColor::fromHsv(15+30*k,255,255));
        ui->plot->plottable(k)->setPen(pen);

        checkboxs[k].setChecked(false);
        QObject::connect(&checkboxs[k],SIGNAL(stateChanged(int)),this,SLOT(checkCheckboxs(int)));
    }

    setLabels();
    loadSettings();

    checkCheckboxs();
    set_button = new QPushButton("Set");
    grid_layout_spinbox->addWidget(set_button,QGPIOWIDGET_IOCOUNT,1);
    QObject::connect(set_button,SIGNAL(released()),this,SLOT(sendGPIO()));

    ui->channels_frame->setLayout(grid_layout_checkbox);
    ui->frame_send->setLayout(grid_layout_spinbox);
    ui->frame_buttons->setLayout(grid_layout_buttons);

    //start timer
    startTimer(20,Qt::PreciseTimer);

    setAttribute(Qt::WA_DeleteOnClose);
    show();
}

QGPIOWidget::~QGPIOWidget()
{
    saveSettings();
    delete ui;
}

QVector<float> QGPIOWidget::getOutDoubles()
{
    return double_list;
}

QVector<int> QGPIOWidget::getOutInts()
{
    return integer_list;
}

void QGPIOWidget::setInDoubles(QVector<float> doubles)
{
    double_list = doubles;
}

void QGPIOWidget::setInInts(QVector<int> ints)
{
    integer_list = ints;
}

void QGPIOWidget::loadSettings()
{
    QSettings settings("RobSoft", "QRoboticsCenter");

    // set window group
    settings.beginGroup("QGPIOWidget");

    // restore window settings
    resize(settings.value("size", QSize(400, 400)).toSize());
    move(settings.value("pos", QPoint(200, 200)).toPoint());

    // restore channel names
    settings.beginReadArray("ChannelNames");
    for(int k = 0;k < QGPIOWIDGET_IOCOUNT;k++){
        settings.setArrayIndex(k);
        if(settings.contains("input")){
            if(!settings.value("input").toString().isEmpty())
                checkboxlabels[k].setText(settings.value("input").toString());
        }
        if(settings.contains("output")){
            if(!settings.value("output").toString().isEmpty())
                spinboxlabels[k].setText(settings.value("output").toString());
        }
        checkboxs[k].setChecked(settings.value("checked").toBool());
        spinboxs[k].setValue(settings.value("value").toDouble());
    }
    settings.endArray();
    settings.endGroup();
}

void QGPIOWidget::saveSettings()
{
    QSettings settings("RobSoft", "QRoboticsCenter");

    // set window group
    settings.beginGroup("QGPIOWidget");

    // save window settings
    settings.setValue("size", size());
    settings.setValue("pos", pos());

    // save channel states
    settings.beginWriteArray("ChannelNames");
    for(int k = 0;k < QGPIOWIDGET_IOCOUNT;k++){
        settings.setArrayIndex(k);
        settings.setValue("input",checkboxlabels[k].text());
        settings.setValue("checked",checkboxs[k].isChecked());
        settings.setValue("output",spinboxlabels[k].text());
        settings.setValue("value",spinboxs[k].value());
    }
    settings.endArray();
    settings.endGroup();
}

void QGPIOWidget::setLabels()
{
    int k;
    for(k = 0;k < QGPIOWIDGET_FLOAT_COUNT;k++){
        spinboxlabels[k].setText("FloatChannel" + QString::number(k));
        checkboxlabels[k].setText("FloatChannel" + QString::number(k));
    }
    for(k = 0;k < QGPIOWIDGET_INT_COUNT;k++){
        spinboxlabels[QGPIOWIDGET_FLOAT_COUNT + k].setText("IntChannel" + QString::number(k));
        checkboxlabels[QGPIOWIDGET_FLOAT_COUNT + k].setText("IntChannel" + QString::number(k));
    }
    for(k = 0;k < QGPIOWIDGET_IOCOUNT;k++){
        QObject::connect(&checkboxlabels[k],SIGNAL(editingFinished()),this,SLOT(inputLabelsSend()));
    }
}

bool QGPIOWidget::running()
{
    return !_paused;
}

bool QGPIOWidget::paused()
{
    return _paused;
}

void QGPIOWidget::mavlinkMsgReceived(mavlink_message_t msg)
{
    switch(msg.msgid){
        case MAVLINK_MSG_ID_GPIO:{
            mavlink_gpio_t gpio;
            mavlink_msg_gpio_decode(&msg, &gpio);

            _time = gpio.time*0.001;
            for(unsigned int k=0;k<QGPIOWIDGET_FLOAT_COUNT;k++){ double_list[k] = gpio.gpio_float[k]; }
            for(unsigned int k=0;k<QGPIOWIDGET_INT_COUNT;k++){ integer_list[k] = gpio.gpio_int[k]; }
        break; }
    }
}

void QGPIOWidget::timerEvent(QTimerEvent *event)
{
    int k;
    _time += 0.05;

    for(k = 0; k < QGPIOWIDGET_FLOAT_COUNT ; k++){
        ui->plot->addDataPoint(_time, double_list[k], k);
    }
    for(k = 0; k < QGPIOWIDGET_INT_COUNT ; k++){
        ui->plot->addDataPoint(_time, integer_list[k], k+QGPIOWIDGET_FLOAT_COUNT);
    }

    if(running()){
        ui->plot->reDraw();
    }
}

void QGPIOWidget::keyPressEvent(QKeyEvent *event)
{
    switch(event->key()){
    case Qt::Key_P:
        _paused = !_paused;
        break;
    }
}

void QGPIOWidget::setGPIO(QVector<float> d, QVector<int> i)
{
    setInDoubles(d);
    setInInts(i);
}

void QGPIOWidget::setPrint(QString text)
{

}

void QGPIOWidget::checkCheckboxs(int i)
{
    for(unsigned int k = 0;k < QGPIOWIDGET_IOCOUNT; k++){
        ui->plot->plottable(k)->setVisible(checkboxs[k].checkState() != Qt::Unchecked);
    }
}

void QGPIOWidget::inputLabelsSend()
{
    QStringList labels;
    labels.reserve(QGPIOWIDGET_IOCOUNT);

    for(int k = 0;k < QGPIOWIDGET_IOCOUNT;k++){
        labels.append(checkboxlabels[k].text());
    }

    emit inputLabelsSet(labels);
}

void QGPIOWidget::sendGPIO()
{
    int k;
    int ints[4];
    float floats[8];

    for(k=0;k<QGPIOWIDGET_FLOAT_COUNT;k++){
        floats[k] = spinboxs[k].value();
    }
    for(k=0;k<QGPIOWIDGET_INT_COUNT;k++){
        ints[k] = spinboxs[QGPIOWIDGET_FLOAT_COUNT+k].value();
    }

    mavlink_message_t msg;
    mavlink_msg_gpio_pack(0,0,&msg,0,0,floats,ints);

    emit mavlinkMsgSend(msg);
    emit gpioSet(double_list, integer_list);
}

void QGPIOWidget::sendEvent(uint16_t event)
{
    mavlink_message_t msg;
    mavlink_msg_event_pack(0,0,&msg,event);

    emit mavlinkMsgSend(msg);
}

void QGPIOWidget::sendButtonEvent(int id)
{
    emit eventButtonPressed(id);
    sendEvent(QGPIOWidget::BUTTONX_PRESSED + id);
}
