#include "qmapwidget.h"

QMapWidget::QMapWidget(QWidget *parent) :
    QWidget(parent),
    _pose(QVector3D(0.0,0.0,0.0)),
    _scale(1.0)
{
    // set sizes
    setSize(1.0);
    setRange(1.0);
    setCenter();

    // set pen styles
    _robot_pen.setColor(Qt::black);
    _robot_pen.setWidth(2);
    _robot_brush.setColor(Qt::green);
    _robot_brush.setStyle(Qt::SolidPattern);
    _point_pen.setColor(Qt::black);
    _point_pen.setWidth(2);
    _tail_pen.setColor(Qt::blue);
    _tail_pen.setWidth(2);
    _tail_pen.setStyle(Qt::SolidLine);

    // set black background
    QPalette Pal(palette());
    Pal.setColor(QPalette::Background, Qt::white);
    this->setAutoFillBackground(true);
    this->setPalette(Pal);
}

void QMapWidget::setSize(double size)
{
    if(_size > 0.0){
        _size = size;
        _robot = QPolygonF();
        _robot.append(QPointF(1.0,0.0)*size);
        _robot.append(QPointF(-0.5,-0.7)*size);
        _robot.append(QPointF(-0.25,0.0)*size);
        _robot.append(QPointF(-0.5,0.7)*size);
    }
}

QVector3D QMapWidget::getPose()
{
    return _pose;
}

void QMapWidget::setPose(QVector3D pose)
{
    _pose = pose;
    update();
}

void QMapWidget::setPosition(QVector2D position)
{
    _pose = QVector3D(position,_pose.z());
    update();
}

void QMapWidget::setOrientation(double orientation)
{
    _pose.setZ(orientation);
    update();
}

void QMapWidget::addPoint(QPointF point)
{
    _points.append(point);
    update();
}

void QMapWidget::addTailPoint(QPointF point)
{
    _tail.append(point);
    if(_tail.size() > 100)
        _tail.pop_front();
}

void QMapWidget::setRange(double radius)
{
    _range = radius;
    setScale();
}

void QMapWidget::setScale()
{
    _scale = qMin(this->width(),this->height())/(2.0*_range);
}

void QMapWidget::setCenter()
{
    _center = QPointF(this->width(),this->height())/2.0;
}

void QMapWidget::paintEvent(QPaintEvent *)
{
    addTailPoint(_pose.toPointF());

    QPainter painter(this);
    painter.drawRect(rect());

    painter.translate(_center);
    painter.scale(1.0,-1.0);
    QTransform transform = QTransform::fromScale(_scale,_scale);

    painter.setPen(_point_pen);
    painter.drawPoints(transform.map(_points));

    painter.setPen(_tail_pen);
    painter.drawPolyline(transform.map(_tail));

    painter.setPen(_robot_pen);
    painter.setBrush(_robot_brush);
    painter.drawPolygon(transform.translate(_pose.x(),_pose.y()).rotateRadians(_pose.z()).map(_robot));
}

void QMapWidget::resizeEvent(QResizeEvent *)
{
    setScale();
    setCenter();
}

