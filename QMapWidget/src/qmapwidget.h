#ifndef QMAPWIDGET_H
#define QMAPWIDGET_H

#include <QWidget>
#include <QPolygon>
#include <QVector3D>
#include <QPointF>
#include <QPainter>

class QMapWidget : public QWidget
{
    Q_OBJECT
public:
    explicit QMapWidget(QWidget *parent = 0);

    void setRange(double radius);

    void setSize(size_t size);
    QVector3D getPose();
    void addPoint(const QPointF &point);

protected:
    virtual void paintEvent(QPaintEvent *e);

private:
    QVector3D _pose;
    QPolygonF _points;
    QPolygonF _robot;

    QPointF _center;
    double _scale;
    double _range;
    size_t _size;

    QPen _robot_pen;
    QBrush _robot_brush;
    QPen _point_pen;

    void setScale();
    void setCenter();

signals:

public slots:
    void setPose(const QVector3D &pose);
    void setOrientation(double orientation);

};

#endif // QMAPWIDGET_H
