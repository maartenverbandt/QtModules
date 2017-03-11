#ifndef QTUDPREADER_H
#define QTUDPREADER_H

#include <qdataportinterface.h>
#include <qudpreaderwidget.h>
#include <mavlink.h>

template <typename T> class QTUdpReader : public QDataPortInterface
{
public:
    QTUdpReader(QString name, QWidget* parent = 0):
        _udp_reader(new QUdpReaderWidget(sizeof(T), name, parent))
    {

    }

    T getTPacket(){
        QByteArray line = _udp_reader->readLine();
        T* t = reinterpret_cast<T*>(line.data());
        return (*t);
    }

    virtual QVariant getPacket(){
        QVariant t;
        t.setValue(getTPacket());
        return t;
    }

    virtual QWidget* getWidget(){
        return _udp_reader;
    }

    virtual bool enabled(){
        return _udp_reader->enabled();
    }

    virtual void reset(){
        _udp_reader->getUdpReader()->reset();
    }

private:
    QUdpReaderWidget* _udp_reader;

};

class QGpioUdpReader: public QTUdpReader<mavlink_gpio_t>{
public:
    QGpioUdpReader(QWidget *parent) :
        QTUdpReader<mavlink_gpio_t>("gpio",parent)
    {}
};

class QPositionCmdUdpReader: public QTUdpReader<mavlink_position_cmd_t>{
public:
    QPositionCmdUdpReader(QWidget *parent) :
        QTUdpReader<mavlink_position_cmd_t>("position cmd",parent)
    {}
};

#endif // QTUDPREADER_H
