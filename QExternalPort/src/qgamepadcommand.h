#ifndef QGAMEPADCOMMAND_H
#define QGAMEPADCOMMAND_H

#include <QObject>
#include <qdataportinterface.h>
#include <qgamepadbutton.h>

class QGamepadCommand : public QDataPortInterface
{
    Q_OBJECT

public:
    explicit QGamepadCommand(QObject *parent = 0);

    virtual QVariant getPacket() = 0;
    virtual QWidget* getWidget(){ return QWidget(); }

    virtual bool enabled(){ return true; }
    virtual void reset(){}

protected:
    // QGamepadCommandWidget* w;
    QMap<QString,QGamepadButton*> _map;

    void add(QString command);
    bool configured(QString command);

signals:

public slots:
};

#endif // QGAMEPADCOMMAND_H
