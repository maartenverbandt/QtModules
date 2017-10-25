#include <QtGui>
#include <QApplication>
#include <QDebug>

#include <qserialprotocol.h>
#include <qheartbeatdetector.h>
#include <QtSerialPort/QSerialPort>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSerialPort *serial = new QSerialPort("ttyACM0");
    if( serial->open(QIODevice::ReadWrite) ) {
        QSerialProtocol *protocol = new QSerialProtocol(serial);
        QHeartbeatDetector *detector = new QHeartbeatDetector();

        QDataNode::connect(protocol, detector);
    } else {
        qDebug() << "Cannot open serial port" << serial->portName();
    }

    return a.exec();
}
