#include "qimucalibrationwidget.h"
#include "ui_qimucalibrationwidget.h"

QTimer QIMUCalibrationWidget::_refresher(0);

QIMUCalibrationWidget::QIMUCalibrationWidget(QWidget *parent, imu_t *imu) :
    QWidget(parent),
    _imu(imu),
    _mode(IMU_CALIBRATION_IDLE),
    _calibration(IMU_CALIBRATION_IDLE),
    ui(new Ui::QIMUCalibrationWidget)
{
    ui->setupUi(this);

    _samples = 0;
    _acc_old(3) = 1.0;
    ui->numberSamples->setRange(1,100000);
    ui->numberSamples->setValue(500);

    /*Setup IMU graphs*/
    ui->omega_plot->init(10.0, 1);
    ui->omega_plot->graph(0)->setPen(QPen(Qt::blue));

    _xy_curve = new QCPCurve(ui->xy_plot->xAxis,ui->xy_plot->yAxis);
    _xy_curve->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDot,Qt::transparent,Qt::blue,2));
    ui->xy_plot->addPlottable(_xy_curve);
    ui->xy_plot->xAxis->setRange(-QIMUCALIB_XYZ_SCALE,QIMUCALIB_XYZ_SCALE);
    ui->xy_plot->yAxis->setRange(-QIMUCALIB_XYZ_SCALE,QIMUCALIB_XYZ_SCALE);

    _yz_curve = new QCPCurve(ui->yz_plot->xAxis,ui->yz_plot->yAxis);
    _yz_curve->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDot,Qt::transparent,Qt::blue,2));
    ui->yz_plot->addPlottable(_yz_curve);
    ui->yz_plot->xAxis->setRange(-QIMUCALIB_XYZ_SCALE,QIMUCALIB_XYZ_SCALE);
    ui->yz_plot->yAxis->setRange(-QIMUCALIB_XYZ_SCALE,QIMUCALIB_XYZ_SCALE);

    _xz_curve = new QCPCurve(ui->xz_plot->xAxis,ui->xz_plot->yAxis);
    _xz_curve->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDot,Qt::transparent,Qt::blue,2));
    ui->xz_plot->addPlottable(_xz_curve);
    ui->xz_plot->xAxis->setRange(-QIMUCALIB_XYZ_SCALE,QIMUCALIB_XYZ_SCALE);
    ui->xz_plot->yAxis->setRange(-QIMUCALIB_XYZ_SCALE,QIMUCALIB_XYZ_SCALE);

    /*Setup refresher timer*/
    QObject::connect(&_refresher, SIGNAL(timeout()), this, SLOT(refresh()));
    _refresher.start(100);
    _time = 0;
}

QIMUCalibrationWidget::~QIMUCalibrationWidget()
{
    delete ui;
}

void QIMUCalibrationWidget::setImu(imu_t *imu)
{
    delete _imu;
    _imu = NULL;

    _imu = imu;
}

void QIMUCalibrationWidget::display(QString s)
{
    ui->textOutput->setText(ui->textOutput->text() + s);
}

void QIMUCalibrationWidget::refresh()
{
    switch(_mode){
        case IMU_CALIBRATION_ACC:{
            //Read raw imu
            Eigen::Vector3d a;
            a << _imu->_acc_raw[0], _imu->_acc_raw[1], _imu->_acc_raw[2];

            //Calculate angle in between new and old vector
            double gamma = acos(a.dot(_acc_old)/(a.norm()*_acc_old.norm()))*57.3;
            _acc_old = a;
            if((gamma<10)&&(!(gamma != gamma)==0)){
                _A(_samples,0) = a(0,0)*a(0,0);
                _A(_samples,1) = a(1,0)*a(1,0);
                _A(_samples,2) = a(2,0)*a(2,0);
                _A(_samples,3) = 2*a(0,0);
                _A(_samples,4) = 2*a(1,0);
                _A(_samples,5) = 2*a(2,0);

                _samples++;
                ui->progressBar->setValue(_samples);
                if(_samples==_numberSamples){
                    this->calibrateAcc();
                }
                this->plotData();
            }

            _time += 0.1;
            if(!(gamma != gamma)){
                ui->omega_plot->addDataPoint(_time,gamma,0);
                ui->omega_plot->reDraw();
            }
        break;
        }

        case IMU_CALIBRATION_GYRO:{
            //Read raw gyro
            Eigen::Vector3d g;
            g << _imu->_gyro_raw[0], _imu->_gyro_raw[1], _imu->_gyro_raw[2];
            _A += g;

            _samples++;
            ui->progressBar->setValue(_samples);
            if(_samples==_numberSamples){
                this->calibrateGyro();
            }
        }

    }
}

void QIMUCalibrationWidget::calibrateAcc()
{
    Eigen::MatrixXd s = (_A.transpose()*_A).ldlt().solve(_A.transpose()*Eigen::MatrixXd::Ones(_numberSamples,1));
    Eigen::Vector3d st = (s.block<3,1>(0,0)).cwiseSqrt();
    Eigen::Vector3d lt = s.block<3,1>(3,0);


    //Solution for a = s*a_m - b with the acceleration in g
    double gamma = 1/sqrt(1 + (lt.cwiseQuotient(st)).squaredNorm());
    _scale = st*gamma;
    _offset = gamma*lt.cwiseQuotient(st);

    // convert to teensy / rescale calibration to mm/s2
    _offset = -_offset.cwiseQuotient(_scale);
    _scale *= 9810;

    _mode = IMU_CALIBRATION_IDLE;
    this->display(QString("Acceleration calibration finised.\nScale =\n   (%1,\n    %2,\n    %3)\nOffset =\n   (%4,\n    %5,\n    %6)\n").arg(_scale(0,0)).arg(_scale(1,0)).arg(_scale(2,0)).arg(_offset(0,0)).arg(_offset(1,0)).arg(_offset(2,0)));

    _calibration = IMU_CALIBRATION_ACC;
}

void QIMUCalibrationWidget::calibrateGyro()
{
    _scale = Eigen::Vector3d::Zero();
    _offset = _A/_samples;
    _mode = IMU_CALIBRATION_IDLE;
    this->display(QString("Gyro calibration finised.\nOffset =\n   (%1,\n    %2,\n    %3)\n").arg(_offset(0,0)).arg(_offset(1,0)).arg(_offset(2,0)));

    _calibration = IMU_CALIBRATION_GYRO;
}

void QIMUCalibrationWidget::plotData()
{
    _xy_curve->addData(_acc_old(0,0),_acc_old(1,0));
    _yz_curve->addData(_acc_old(1,0),_acc_old(2,0));
    _xz_curve->addData(_acc_old(0,0),_acc_old(2,0));

    //ui->xy_plot->rescaleAxes();
    ui->xy_plot->replot();
    //ui->yz_plot->rescaleAxes();
    ui->yz_plot->replot();
    //ui->xz_plot->rescaleAxes();
    ui->xz_plot->replot();
}

void QIMUCalibrationWidget::on_calibrateAccButton_clicked()
{
    if(_mode!=IMU_CALIBRATION_ACC){
        _mode = IMU_CALIBRATION_ACC;
        _numberSamples = ui->numberSamples->value();
        _acc_old << _imu->_acc_raw[0], _imu->_acc_raw[1], _imu->_acc_raw[2];

        _xy_curve->clearData();
        _yz_curve->clearData();
        _xz_curve->clearData();

        _A.resize(_numberSamples,6);
        ui->progressBar->setValue(0);
        ui->progressBar->setRange(0,_numberSamples);
        ui->textOutput->setText(QString(""));
        this->display(QString("Acceleration calibration started:\nRequested samples:\n    %1\nEstimated time:\n    %2 [s]\n").arg(_numberSamples).arg((int)(_numberSamples*0.05)));
    }
    else{
        _mode = IMU_CALIBRATION_IDLE;
        this->display(QString("Acceleration calibration terminated."));
    }

}

void QIMUCalibrationWidget::on_calibrateGyroButton_clicked()
{
    if(_mode!=IMU_CALIBRATION_GYRO){
        _mode = IMU_CALIBRATION_GYRO;
        _numberSamples = ui->numberSamples->value();

        _xy_curve->clearData();
        _yz_curve->clearData();
        _xz_curve->clearData();

        _A.resize(3,1);
        ui->progressBar->setValue(0);
        ui->progressBar->setRange(0,_numberSamples);
        ui->textOutput->setText(QString(""));
        this->display(QString("Gyro Calibration started:\nRequested samples:\n    %1\nEstimated time:\n    %2 [s]\n").arg(_numberSamples).arg((int)(_numberSamples*0.05)));
    }
    else{
        _mode = IMU_CALIBRATION_IDLE;
        this->display(QString("Gyro Calibration terminated."));
    }
}

void QIMUCalibrationWidget::on_pushButton_clicked()
{
    switch (_calibration) {
    case IMU_CALIBRATION_ACC:
        emit accCalibration(QVector3D(_scale(0),_scale(1),_scale(2)), QVector3D(_offset(0),_offset(1),_offset(2)));
        break;
    case IMU_CALIBRATION_GYRO:
        emit gyroCalibration(QVector3D(_scale(0),_scale(1),_scale(2)), QVector3D(_offset(0),_offset(1),_offset(2)));
        break;
    default:
        break;
    }
}
