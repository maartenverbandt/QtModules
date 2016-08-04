#include "qloggerdialog.h"
#include "ui_qloggerdialog.h"

QLoggerDialog::QLoggerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QLoggerDialog),
    start(0)
{
    ui->setupUi(this);

    setAttribute(Qt::WA_DeleteOnClose);
    ui->recordButton->setChecked(true);
    show();
}

QLoggerDialog::~QLoggerDialog()
{
    if(ui->recordButton->isChecked())
        on_recordButton_clicked(false); //write data to log file

    delete ui;
}

void QLoggerDialog::mavlinkMsgReceived(mavlink_message_t msg)
{
    if(ui->recordButton->isChecked()){
        switch(msg.msgid){
            case MAVLINK_MSG_ID_GPIO:{
                mavlink_gpio_t gpio;
                mavlink_msg_gpio_decode(&msg, &gpio);

                time_vector.append(gpio.time*0.001);
                for(int k=0;k<4;k++){
                    int_vector[k].append(gpio.gpio_int[k]);
                    double_vector[k].append(gpio.gpio_float[k]);
                    double_vector[k+4].append(gpio.gpio_float[k+4]);
                }

                if(start == 0){ start = gpio.time; }
                ui->recordButton->setText(QString::number((gpio.time-start)/1000) + " s");
            break; }
        }
    }
}

//matio implementation

#ifdef LOGGER_MATIO
void QLoggerDialog::on_recordButton_clicked(bool checked)
{
    if(checked){
        //start logging
        start = 0;
        time_vector.clear();
        for(int k=0;k<4;k++){
            int_vector[k].clear();
            double_vector[k].clear();
            double_vector[k+4].clear();
        }
    } else {
        //write to file
        mat_t *matfp = Mat_CreateVer("test.mat",NULL,MAT_FT_MAT4);
        matvar_t *matvar;
        double *time;
        int *data[4];
        double floats[2][100];
        double* test;


        size_t dim[2] = {4,int_vector[0].length()};
        qDebug() << int_vector[0].length();
        for(int k=0;k<4;k++){
            data[k] = int_vector[k].data();
        }
        matvar = Mat_VarCreate("ints",MAT_C_INT32,MAT_T_INT32,2,dim,data,0);
        Mat_VarWrite(matfp,matvar,MAT_COMPRESSION_NONE);
        Mat_VarFree(matvar);

        dim[0] = time_vector.length();
        dim[1] = 1;
        qDebug() << time_vector.length();
        time = time_vector.data();
        matvar = Mat_VarCreate("time",MAT_C_DOUBLE,MAT_T_DOUBLE,2,dim,time,0);
        Mat_VarWrite(matfp,matvar,MAT_COMPRESSION_NONE);
        Mat_VarFree(matvar);

        dim[0] = double_vector[0].length();
        dim[1] = 1;
        qDebug() << double_vector[0].length();
//        for(int k=0;k<8;k++){
//            floats[k] = double_vector[k].data();
//        }
        test = double_vector[1].data();
        matvar = Mat_VarCreate("test",MAT_C_DOUBLE,MAT_T_DOUBLE,2,dim,test,0);
        Mat_VarWrite(matfp,matvar,MAT_COMPRESSION_NONE);
        Mat_VarFree(matvar);

        dim[1] = 100; //double_vector[0].length();
        dim[0] = 2;
        qDebug() << double_vector[0].length();
        for(int k=1;k<2;k++){
            //memcpy(floats[k],double_vector[k].data(),double_vector[k].size());
            for(int j = 1;j<100;j++){
                floats[k][j] = j;
            }
        }
        matvar = Mat_VarCreate("floats",MAT_C_DOUBLE,MAT_T_DOUBLE,2,dim,&floats,0);
        Mat_VarWrite(matfp,matvar,MAT_COMPRESSION_NONE);
        Mat_VarFree(matvar);

        const int first = double_vector[0].size();
        const int second = 2; //columns
        double array2d[first][second];

        // fill 2d array
        for (int i = 0; i < first; i++)
            for (int j = 0; j < second; j++)
                //memcpy(&array2d[0][j],double_vector[j+1].data(),double_vector[j+1].size());
                array2d[i][j] = double_vector[j+1][i];

        // write
        char* fieldname2d = "array2d";
        size_t dim2d[2] = { second,first };
        matvar_t *variable2d = Mat_VarCreate(fieldname2d, MAT_C_DOUBLE, MAT_T_DOUBLE, 2, dim2d, &array2d, 0); //rank 2
        Mat_VarWrite(matfp, variable2d, MAT_COMPRESSION_NONE);
        Mat_VarFree(variable2d);

        Mat_Close(matfp);

        //set button
        ui->recordButton->setText("Record");
    }
}

#else
void QLoggerDialog::on_recordButton_clicked(bool checked)
{
    if(checked){
        //start logging
        start = 0;
        time_vector.clear();
        for(int k=0;k<4;k++){
            int_vector[k].clear();
            double_vector[k].clear();
            double_vector[k+4].clear();
        }
    } else {
        QDir().mkdir("logs");
        QFile log("logs/log_" + QDateTime::currentDateTime().toString("MM_dd_HH_mm"));
        log.open(QIODevice::ReadWrite);

        int j,k;
        QString line;
        for(k=0;k<time_vector.length();k++){
            line = QString::number(time_vector[k]);
            for(j=0;j<4;j++){
               line +=  "\t" + QString::number(int_vector[j][k]);
            }
            for(j=0;j<8;j++){
               line +=  "\t" + QString::number(double_vector[j][k]);
            }
            line += QString("\n");
            log.write(line.toLocal8Bit());
        }
        log.close();

        ui->recordButton->setText("Record");
    }
}
#endif //LOGGER_MATIO
