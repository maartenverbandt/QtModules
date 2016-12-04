#ifndef QMAPWIDGET_H
#define QMAPWIDGET_H

#include <QWidget>
#include <QPolygon>
#include <QVector2D>
#include <QVector3D>
#include <QPointF>
#include <QPainter>

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
    QVector3D _pose;
    QPolygonF _points;
    QPolygonF _robot;

    QPointF _center;
    double _scale;
    double _range;
    double _size;

    QPen _robot_pen;
    QBrush _robot_brush;
    QPen _point_pen;

    void setScale();
    void setCenter();

signals:

public slots:
    void setPose(QVector3D pose);
    void setPosition(QVector2D position);
    void setOrientation(double orientation);

};

#endif // QMAPWIDGET_H
