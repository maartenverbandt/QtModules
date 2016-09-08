#ifndef QIMU_TYPEDEF
#define QIMU_TYPEDEF

typedef struct{
    int ID;

    int _acc_raw[3];
    int _gyro_raw[3];
    int _mag_raw[3];

    float _acc_calib[3];
    float _gyro_calib[3];
    float _mag_calib[3];
} imu_t;

typedef struct{
    int ID;

    double _roll;
    double _pitch;
    double _yaw;

    double _Droll;
    double _Dpitch;
    double _Dyaw;
} ahrs_t;

#endif // QIMU_TYPEDEF

