#ifndef QMAPWIDGET_H
#define QMAPWIDGET_H

#include <QWidget>
#include <QPolygon>
#include <QVector2D>
#include <QVector3D>
#include <QPointF>
#include <QPainter>

#include <qrobotelement.h>

class QMapWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QMapWidget(QWidget *parent = 0);

    void setRange(double radius);

    void setSize(double size);
    QVector3D getPose();
    void addPoint(QPointF point);

protected:
    virtual void paintEvent(QPaintEvent *e);
    virtual void resizeEvent(QResizeEvent *);

private:
    QRobotElement robotelement;
    QVector3D _pose;
    QVector2D _velocity;
    QPolygonF _points;
    QPolygonF _robot;
    QPolygonF _speed;
    QPolygonF _tail;

    QPointF _center;
    double _scale;
    double _range;
    double _size;

    QPen _robot_pen;
    QBrush _robot_brush;
    QPen _point_pen;
    QPen _tail_pen;

    void setScale();
    void setCenter();

    void addTailPoint(QPointF point);

signals:

public slots:
    void setPose(QVector3D pose);
    void setPosition(QVector2D position);
    void setOrientation(double orientation);

    void setGlobalVelocity(QVector2D velocity);

};

#endif // QMAPWIDGET_H
