#ifndef QTUDPWRITER_H
#define QTUDPWRITER_H

#include <qmeasurementportinterface.h>
#include <qudpwriterwidget.h>
#include <mavlink.h>

template <typename T> class QTUdpWriter : public QMeasurementPortInterface
{
public:
    QTUdpWriter(QString name, QWidget* parent = 0):
        _udp_writer(new QUdpWriterWidget(name, parent))
    {

    }

    void setPacket(QVariant packet){
        if(packet.canConvert<T>()){
            T t = packet.value<T>();
            setPacket(t);
        }
    }

    virtual void setPacket(T packet){
        QByteArray bytes = QByteArray((char*)(&packet),sizeof(T));
        _udp_writer->writeLine(bytes);
    }

    virtual QWidget* getWidget(){
        return _udp_writer;
    }

    virtual bool enabled(){
        return _udp_writer->enabled();
    }

    virtual void reset(){
        _udp_writer->getUdpWriter()->reset();
    }

private:
    QUdpWriterWidget* _udp_writer;

};

class QGpioUdpWriter: public QTUdpWriter<mavlink_gpio_t>{
public:
    QGpioUdpWriter(QWidget *parent) :
        QTUdpWriter<mavlink_gpio_t>("gpio",parent)
    {}
};

class QPoseUdpWriter: public QTUdpWriter<mavlink_pose_t>{
public:
    QPoseUdpWriter(QWidget *parent) :
        QTUdpWriter<mavlink_pose_t>("pose",parent)
    {}
};

class QAttitudeUdpWriter: public QTUdpWriter<mavlink_attitude_t>{
public:
    QAttitudeUdpWriter(QWidget *parent) :
        QTUdpWriter<mavlink_attitude_t>("attitude",parent)
    {}
};

#endif // QTUDPWRITER_H
