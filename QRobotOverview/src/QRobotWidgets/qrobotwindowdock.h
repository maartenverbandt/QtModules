#ifndef QSHOWDOCKACTION_H
#define QSHOWDOCKACTION_H

#include <QAction>
#include <QDockWidget>
#include <qrobotwindow.h>

class QRobotWindowDock : public QDockWidget
{
    Q_OBJECT
public:
    explicit QRobotWindowDock(const QString& text, QRobotWindow *window);
    QAction *showAction();

protected:
    QRobotWindow *_window;

private:
    QAction *_show;

protected slots:
    virtual void on_show(){}
    virtual void on_close(){}

};

#endif // QSHOWDOCKACTION_H
