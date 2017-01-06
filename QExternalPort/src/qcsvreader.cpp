#include "qcsvreader.h"

QCsvReader::QCsvReader(QObject *parent) :
    QObject(parent),
    _file(new QFile(this)),
    _stream(new QTextStream(_file))
{

}

void QCsvReader::reset()
{
    _stream->seek(0); //go to start of csv
}

bool QCsvReader::setFile(QString filename)
{
    if(_file->isOpen()){
        _file->close();
    }

    _file->setFileName(filename);
    if(_file->exists()){
        _file->open(QFile::ReadOnly);
        reset();
        return true;
    }

    return false;
}

QFile *QCsvReader::getFile()
{
    return _file;
}

QList<double> QCsvReader::readLine()
{
    // read line
    QStringList strings = _stream->readLine().split('\t',QString::SkipEmptyParts);
    QList<double> values;
    QListIterator<QString> i(strings);
    while(i.hasNext())
        values.append(i.next().toDouble());

    // check end of file
    if(_stream->atEnd()){
        atEnd();
        reset();
    }

    return values;
}

double QCsvReader::progress()
{
    return ((double)_stream->pos()/_file->size());
}
