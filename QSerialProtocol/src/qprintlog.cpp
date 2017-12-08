#include "qprintlog.h"

QPrintLog::QPrintLog(QObject *parent) : QDataNode(parent)
{
    //do nothing
}

void QPrintLog::open()
{
    open(parent()->objectName());
}

void QPrintLog::open(QString filename)
{
    _log = new QFile(QDir::tempPath() + QDir::separator() + filename + ".txt",this);
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
    _stitcher->stitch(QString(print.text),32);
    while(_stitcher->hasLine()) {
        QString line = _stitcher->getLine();
        write(line + '\n');
        qDebug() << "stitchreveive: " << line;
        emit newline(line);
    }
}
