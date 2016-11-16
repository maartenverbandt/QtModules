#include "qgpiorecorder.h"
#include <qdebug.h>

QGPIORecorder::QGPIORecorder(QGPIOWidget *gpio, QObject *parent) :
    QAbstractRecorder(parent), _log(NULL),
    _gpio(gpio)
{
    _recorder.setText("GPIO");
}

QString QGPIORecorder::createHeader()
{
    QString header;
    header = "<QGPIORecord>\n";

    // Time
    QDateTime now = QDateTime::currentDateTime();
    header += "\t<time>\n";
    header += "\t\t<year>" + now.toString("yyyy") + "</year>\n";
    header += "\t\t<month>" + now.toString("MM") + "</month>\n";
    header += "\t\t<day>" + now.toString("dd") + "</day>\n";
    header += "\t\t<hour>" + now.toString("HH") + "</hour>\n";
    header += "\t\t<minute>" + now.toString("mm") + "</minute>\n";
    header += "\t</time>\n";

    // Version
    header += "\t<version>2.0</version>\n";

    // Comment
    header += "\t<comment></comment>\n";
    header += "\n";

    // Labels
    header += "\t<labels>\n";
    header += "\t\t<value>time</value>\n";
    QStringList labels = _gpio->getLabels();
    for(int k=0;k<labels.length();k++){
        header += "\t\t<value>" + labels[k] + "</value>\n";
    }
    header += "\t</labels>\n";

    // Data
    header += "\t<data>\n";

    return header;
}

QString QGPIORecorder::createFooter()
{
    QString footer;
    footer += "\t</data>\n";
    footer += "</QGPIORecord>";

    return footer;
}

void QGPIORecorder::gpioReceived(mavlink_gpio_t gpio)
{
    if(isRecording()){
        int k;

        QString line = "\t\t<row>";
        line += QString::number(gpio.time);

        for(k=0;k<8;k++){
            line +=  "\t" + QString::number(gpio.gpio_float[k]);
        }

        for(k=0;k<4;k++){
           line +=  "\t" + QString::number(gpio.gpio_int[k]);
        }

        line += "</row>\n";

        _log->write(line.toLocal8Bit());
    }
}

//OBSOLETE
/*void QGPIORecorder::setLabels(QStringList labels)
{
    _labels = labels;
}*/

void QGPIORecorder::startRecording()
{
    QAbstractRecorder::startRecording(); //emit signals

    _log = openDateFile("log_gpio");
    _log->open(QIODevice::ReadWrite);

    //make header
    _log->write(createHeader().toLocal8Bit());
}

void QGPIORecorder::stopRecording()
{
    QAbstractRecorder::stopRecording(); //emit signals

    //make footer
    _log->write(createFooter().toLocal8Bit());
    _log->close();
}
