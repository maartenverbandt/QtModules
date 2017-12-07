#ifndef QTYPEUDPCOMMAND_H
#define QTYPEUDPCOMMAND_H

#include <qtypecommandinterface.h>
#include <qudpreaderwidget.h>

template <typename T> class QTUdpReader : public QDataPortInterface
{
public:
    QTUdpReader(const QString& name, QWidget* parent = 0):
        QDataPortInterface(parent),
        _udp_reader(new QUdpReaderWidget(sizeof(T), name, parent))
    {

    }

    virtual void transmit_packet(){
        QByteArray line = _udp_reader->readLine();
        if(line.size() > 0) {
            T* t = reinterpret_cast<T*>(line.data());
            emit transmit(*t);
        } else {
            qDebug() << "UDP: no data received";
        }
    }

    virtual QWidget *w() {
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

class QGpioUdpReader: public QTUdpReader<gpio_t>{
public:
    QGpioUdpReader(QWidget *parent) :
        QTUdpReader<gpio_t>("gpio",parent)
    {}
};

class QPositionCmdUdpReader: public QTUdpReader<position_cmd_t>{
public:
    QPositionCmdUdpReader(QWidget *parent) :
        QTUdpReader<position_cmd_t>("position cmd",parent)
    {}
};

#endif // QTYPEUDPCOMMAND_H
