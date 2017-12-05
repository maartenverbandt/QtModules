#include "qprintlog.h"

QPrintLog::QPrintLog(QObject *parent, bool opennow) : QDataNode(parent)
{
    if(opennow)
        open(parent->objectName());
}

void QPrintLog::open(QString robot)
{
    _log = new QFile(QDir::tempPath() + QDir::separator() + robot + ".txt",this);
    if(!_log->open(QIODevice::WriteOnly | QIODevice::Text))
        qDebug() << "Error opening robot log file";
}

void QPrintLog::write(QString line)
{
    _log->write(line.toLatin1());
    _log->flush(); //force a quick update
}

void QPrintLog::receive(print_t print)
{
    if(_stitcher->stitch(QString(print.text),32)){
        write(_stitcher->getLine());
    }
}
