#include "qgpiowidget.h"
#include "ui_qgpiowidget.h"

QGPIOWidget::QGPIOWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QGPIOWidget),
    integer_list({0,0,0,0,0,0,0,0}),
    double_list({0,0,0,0,0,0,0,0}),
    _time(0)
{
    ui->setupUi(this);

    horizontal_layout = new QBoxLayout(QBoxLayout::LeftToRight);
    setLayout(horizontal_layout);

    plot = new QRunningPlot(this);
    plot->init(40,2*QGPIOWIDGET_IOCOUNT); //make graph with 16 functions

    grid_layout_spinbox = new QGridLayout(0);
    grid_layout_checkbox = new QGridLayout(0);

    QPen pen;
    for(int k = 0;k < QGPIOWIDGET_IOCOUNT;k++){
        grid_layout_spinbox->addWidget(new QLabel(QString::number(k+1),this),k,0);
        grid_layout_spinbox->addWidget(&spinboxs[k],k,1);
        grid_layout_spinbox->addWidget(&spinboxs[QGPIOWIDGET_IOCOUNT+k],k,2);

        grid_layout_checkbox->addWidget(new QLabel(QString::number(k+1),this),k,0);
        grid_layout_checkbox->addWidget(&checkboxs[k],k,1);
        grid_layout_checkbox->addWidget(&checkboxs[QGPIOWIDGET_IOCOUNT+k],k,2);

        pen = QPen(QColor(255,0,0));
        //plot->plottable(k)->setPen(pen);

        checkboxs[k].setChecked(false);
        QObject::connect(&checkboxs[k],SIGNAL(stateChanged(int)),this,SLOT(checkCheckboxs(int)));
        checkboxs[k+QGPIOWIDGET_IOCOUNT].setChecked(false);
        QObject::connect(&checkboxs[k+QGPIOWIDGET_IOCOUNT],SIGNAL(stateChanged(int)),this,SLOT(checkCheckboxs(int)));
    }
    checkCheckboxs();
    set_button = new QPushButton("Set");
    grid_layout_spinbox->addWidget(set_button,QGPIOWIDGET_IOCOUNT,2,1,1);
    QObject::connect(set_button,SIGNAL(released()),this,SLOT(sendGPIO()));


    for(int k = 0;k < QGPIOWIDGET_IOCOUNT;k++){
        spinboxs[k].setRange(-1000000,1000000);
        spinboxs[k].setDecimals(0);

        spinboxs[QGPIOWIDGET_IOCOUNT+k].setRange(-1000000,1000000);
        spinboxs[QGPIOWIDGET_IOCOUNT+k].setDecimals(4);
    }

    horizontal_layout->addLayout(grid_layout_checkbox,0);
    horizontal_layout->addWidget(plot,1);
    horizontal_layout->addLayout(grid_layout_spinbox,0);

    //start timer
    startTimer(20,Qt::PreciseTimer);

    setAttribute(Qt::WA_DeleteOnClose);
    show();
}

QGPIOWidget::~QGPIOWidget()
{
    delete ui;
}

void QGPIOWidget::mavlinkMsgReceived(mavlink_message_t msg)
{
    switch(msg.msgid){
        case MAVLINK_MSG_ID_GPIO:{
            mavlink_gpio_t gpio;
            mavlink_msg_gpio_decode(&msg, &gpio);

            _time = gpio.time*0.001;
            for(unsigned int k=0;k<4;k++){ integer_list[k] = gpio.gpio_int[k]; }
            for(unsigned int k=4;k<8;k++){ integer_list[k] = 0; }
            for(unsigned int k=0;k<8;k++){ double_list[k] = gpio.gpio_float[k]; }
        break; }
    }
}

void QGPIOWidget::timerEvent(QTimerEvent *event)
{
    unsigned int k;
    //_time += 0.05;

    //qDebug() << "Adding integer ";
    for(k = 0; k < QGPIOWIDGET_IOCOUNT ; k++){
        plot->addDataPoint(_time, integer_list[k], k);
        //qDebug() << QString::number(k);
    }

    //qDebug() << "Adding double ";
    for(k = 0; k < QGPIOWIDGET_IOCOUNT ; k++){
        plot->addDataPoint(_time, double_list[k], k+QGPIOWIDGET_IOCOUNT);
        //qDebug() << QString::number(k);
    }

    plot->reDraw();
}

void QGPIOWidget::checkCheckboxs(int i)
{
    //qDebug() << "Checking boxes";
    for(unsigned int k = 0;k < (2*QGPIOWIDGET_IOCOUNT); k++){
        plot->plottable(k)->setVisible(checkboxs[k].checkState() != Qt::Unchecked);
    }
}

void QGPIOWidget::sendGPIO()
{
    int ints[8];
    float floats[8];

    for(int k=0;k<QGPIOWIDGET_IOCOUNT;k++){
        ints[k] = spinboxs[k].value();
        floats[k] = spinboxs[QGPIOWIDGET_IOCOUNT+k].value();
    }

    mavlink_message_t msg;
    mavlink_msg_gpio_pack(0,0,&msg,0,0,floats,ints);

    emit mavlinkMsgSend(msg);
}
