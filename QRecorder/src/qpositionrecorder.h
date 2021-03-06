#ifndef QPOSITIONRECORDER_H
#define QPOSITIONRECORDER_H

#include <qabstractrecorder.h>

class QPositionRecorder : public QAbstractRecorder
{
    Q_OBJECT
public:
    QPositionRecorder(QObject* parent = 0);

private:
    virtual QString insertHeader();

public slots:
    virtual void receive(position_t position);

};

#endif // QPOSITIONRECORDER_H
