#ifndef QIMUWIDGET_H
#define QIMUWIDGET_H

#include <QWidget>
#include <QVector>
#include <QTimer>
#include "qimu_typedef.h"
#include <qimucalibrationwidget.h>

namespace Ui {
class QIMUWidget;
}

class QIMUWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QIMUWidget(QWidget *parent = 0, imu_t *imu = new imu_t);
    ~QIMUWidget();

    imu_t *imu();
    ahrs_t *ahrs();
    void setImu(imu_t *imu);
    void setAhrs(ahrs_t *ahrs);

    QIMUCalibrationWidget *imuCalibrationWidget();

public slots:
    void refresh();
    void refresh(double time);

private:
    Ui::QIMUWidget *ui;
    imu_t   *_imu;
    ahrs_t  *_ahrs;

    static QTimer _refresher;
    double _time;

};

#endif // QIMUWIDGET_H
