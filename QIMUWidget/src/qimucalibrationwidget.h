#ifndef QIMUCALIBRATIONWIDGET_H
#define QIMUCALIBRATIONWIDGET_H

#include <QWidget>
#include <QTimer>
#include <QVector3D>
#include <qcustomplot.h>
#include "qimu_typedef.h"
#include <Eigen.h>

#define QIMUCALIB_XYZ_SCALE    17000

typedef enum{
    IMU_CALIBRATION_IDLE,
    IMU_CALIBRATION_ACC,
    IMU_CALIBRATION_GYRO
} imu_calibration_state_t;

namespace Ui {
class QIMUCalibrationWidget;
}

class QIMUCalibrationWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QIMUCalibrationWidget(QWidget *parent = 0, imu_t *imu = new imu_t);
    ~QIMUCalibrationWidget();

    void setImu(imu_t* imu);

private:
    Ui::QIMUCalibrationWidget *ui;

    imu_t* _imu;
    static QTimer _refresher;
    double _time;

    imu_calibration_state_t _mode;
    imu_calibration_state_t _calibration;
    uint32_t _samples;
    uint32_t _numberSamples;
    Eigen::MatrixXd _A;
    Eigen::Vector3d _acc_old;

    Eigen::Vector3d _scale;
    Eigen::Vector3d _offset;

    QCPCurve* _xy_curve;
    QCPCurve* _yz_curve;
    QCPCurve* _xz_curve;

    void calibrateAcc();
    void calibrateGyro();

    void plotData();
    void display(QString s);

private slots:
    void refresh();

    void on_calibrateAccButton_clicked();
    void on_calibrateGyroButton_clicked();

    void on_pushButton_clicked();

signals:
    void accCalibration(QVector3D scale, QVector3D offset);
    void gyroCalibration(QVector3D scale, QVector3D offset);
};

#endif // QIMUCALIBRATIONWIDGET_H
