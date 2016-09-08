#include "qimuwidget.h"
#include "ui_qimuwidget.h"

#define IMUWIDGET_PUSHBUTTON_RAW        0
#define IMUWIDGET_PUSHBUTTON_AHRS       1
#define IMUWIDGET_PUSHBUTTON_CALIBRATE  2

#define RAD_TO_DEG  57.295779513

QTimer QIMUWidget::_refresher(0);

QIMUWidget::QIMUWidget(QWidget *parent, imu_t* imu) :
    QWidget(parent),
    _imu(imu),
    _ahrs(NULL),
    ui(new Ui::QIMUWidget)
{
    ui->setupUi(this);

    ui->imuButtonGroup->setId(ui->rawButton, IMUWIDGET_PUSHBUTTON_RAW);
    ui->imuButtonGroup->setId(ui->ahrsButton, IMUWIDGET_PUSHBUTTON_AHRS);
    ui->imuButtonGroup->setId(ui->calibrateButton, IMUWIDGET_PUSHBUTTON_CALIBRATE);

    ui->rawButton->setChecked(true);
    ui->plot_stackedWidget->setCurrentIndex(IMUWIDGET_PUSHBUTTON_RAW);
    QObject::connect(ui->imuButtonGroup,SIGNAL(buttonPressed(int)),ui->plot_stackedWidget,SLOT(setCurrentIndex(int)));

    /*Setup Calibration Widget*/
    ui->calib_widget->setImu(imu);

    /*Setup IMU graphs*/
    ui->imu_plot1->init(5.0, 3);
    ui->imu_plot2->init(5.0, 3);
    ui->imu_plot3->init(5.0, 3);

    ui->imu_plot1->graph(0)->setPen(QPen(Qt::blue));
    ui->imu_plot1->graph(1)->setPen(QPen(Qt::red));
    ui->imu_plot1->graph(2)->setPen(QPen(Qt::black));

    ui->imu_plot2->graph(0)->setPen(QPen(Qt::blue));
    ui->imu_plot2->graph(1)->setPen(QPen(Qt::red));
    ui->imu_plot2->graph(2)->setPen(QPen(Qt::black));

    ui->imu_plot3->graph(0)->setPen(QPen(Qt::blue));
    ui->imu_plot3->graph(1)->setPen(QPen(Qt::red));
    ui->imu_plot3->graph(2)->setPen(QPen(Qt::black));

    /*Setup AHRS graphs*/
    ui->ahrs_plot1->init(5.0, 2);
    ui->ahrs_plot2->init(5.0, 2);
    ui->ahrs_plot3->init(5.0, 2);

    ui->ahrs_plot1->graph(0)->setPen(QPen(Qt::blue));
    ui->ahrs_plot1->graph(1)->setPen(QPen(Qt::black));
    ui->ahrs_plot1->yAxis2->setVisible(true);
    ui->ahrs_plot1->setAxes(ui->ahrs_plot1->xAxis, ui->ahrs_plot1->yAxis2, 1);

    ui->ahrs_plot2->graph(0)->setPen(QPen(Qt::blue));
    ui->ahrs_plot2->graph(1)->setPen(QPen(Qt::black));
    ui->ahrs_plot2->yAxis2->setVisible(true);
    ui->ahrs_plot2->setAxes(ui->ahrs_plot2->xAxis, ui->ahrs_plot2->yAxis2, 1);

    ui->ahrs_plot3->graph(0)->setPen(QPen(Qt::blue));
    ui->ahrs_plot3->graph(1)->setPen(QPen(Qt::black));
    ui->ahrs_plot3->yAxis2->setVisible(true);
    ui->ahrs_plot3->setAxes(ui->ahrs_plot3->xAxis, ui->ahrs_plot3->yAxis2, 1);

    //_refresher = new QTimer(this);
    QObject::connect(&_refresher, SIGNAL(timeout()), this, SLOT(refresh()));
    _refresher.start(50);
    _time = 0;

}

QIMUWidget::~QIMUWidget()
{
    delete ui;
}

imu_t *QIMUWidget::imu()
{
    return _imu;
}

ahrs_t *QIMUWidget::ahrs()
{
    return _ahrs;
}

void QIMUWidget::setImu(imu_t *imu)
{
    ui->calib_widget->setImu(imu); //deletes the object
    _imu = imu;  //assign new object to the pointer

}

void QIMUWidget::setAhrs(ahrs_t *ahrs)
{
    delete _ahrs;
    _ahrs = ahrs;
}

QIMUCalibrationWidget *QIMUWidget::imuCalibrationWidget()
{
    return ui->calib_widget;
}

void QIMUWidget::refresh(double time)
{
    ui->imu_plot1->addDataPoint(time, _imu->_acc_calib[0], 0);
    ui->imu_plot1->addDataPoint(time, _imu->_acc_calib[1], 1);
    ui->imu_plot1->addDataPoint(time, _imu->_acc_calib[2], 2);

    ui->imu_plot2->addDataPoint(time, _imu->_gyro_calib[0], 0);
    ui->imu_plot2->addDataPoint(time, _imu->_gyro_calib[1], 1);
    ui->imu_plot2->addDataPoint(time, _imu->_gyro_calib[2], 2);

    ui->imu_plot3->addDataPoint(time, _imu->_mag_calib[0], 0);
    ui->imu_plot3->addDataPoint(time, _imu->_mag_calib[1], 1);
    ui->imu_plot3->addDataPoint(time, _imu->_mag_calib[2], 2);

    ui->ahrs_plot1->addDataPoint(time, _ahrs->_roll*RAD_TO_DEG, 0);
    ui->ahrs_plot1->addDataPoint(time, _ahrs->_Droll*RAD_TO_DEG, 1);

    ui->ahrs_plot2->addDataPoint(time, _ahrs->_pitch*RAD_TO_DEG, 0);
    ui->ahrs_plot2->addDataPoint(time, _ahrs->_Dpitch*RAD_TO_DEG, 1);

    ui->ahrs_plot3->addDataPoint(time, _ahrs->_yaw*RAD_TO_DEG, 0);
    ui->ahrs_plot3->addDataPoint(time, _ahrs->_Dyaw*RAD_TO_DEG, 1);

    if(this->isVisible()){
        switch(ui->imuButtonGroup->checkedId()){
        case IMUWIDGET_PUSHBUTTON_RAW:
                ui->imu_plot1->reDraw();
                ui->imu_plot2->reDraw();
                ui->imu_plot3->reDraw();
            break;

        case IMUWIDGET_PUSHBUTTON_AHRS:
                ui->ahrs_plot1->reDraw();
                ui->ahrs_plot2->reDraw();
                ui->ahrs_plot3->reDraw();
            break;
        }
    }
}

void QIMUWidget::refresh()
{
    _time += 0.05;
    this->refresh(_time);
}
