#ifndef QEXTERNALPORTDIALOG_H
#define QEXTERNALPORTDIALOG_H

#include <QDialog>
#include <QLayout>
#include <QPushButton>
#include <QButtonGroup>
#include <QStackedWidget>
#include <QAction>
#include <qdataportinterface.h>

class QExternalPortDialog : public QDialog
{
    Q_OBJECT
public:
    explicit QExternalPortDialog(QString name, QWidget *parent = 0);
    ~QExternalPortDialog();

    void addPort(QDataPortInterface *port, QString name);
    QDataPortInterface* getCurrentPort();
    void setCurrentPort(int index);
    QVariant getPacket();

    QAction* getPopupAction();

private:
    QList<QDataPortInterface*> _ports;

    QAction* _popup;
    int _timer_id;

    QHBoxLayout* _layout;
    QHBoxLayout* _controls_layout;
    QVBoxLayout* _button_layout;
    QVBoxLayout* _content_layout;
    QButtonGroup* _buttons;
    QStackedWidget* _stack;

    void layoutSetup();

public slots:
    void startToggled(bool checked);
    void start();
    void stop();
    void reset();

};

#endif // QEXTERNALPORTDIALOG_H
