#ifndef QCSVREADER_H
#define QCSVREADER_H

#include <QObject>
#include <QFile>
#include <QTextStream>

class QCsvReader : public QObject
{
    Q_OBJECT

public:
    explicit QCsvReader(QObject *parent = 0);

    bool setFile(QString filename);
    QFile *getFile();
    void reset();

    QList<double> readLine();
    double progress();

private:
    QFile* _file;
    QTextStream* _stream;

signals:
    void atEnd();

};

#endif // QCSVREADER_H
