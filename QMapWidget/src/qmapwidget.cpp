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

    // set black background
    QPalette Pal(palette());
    Pal.setColor(QPalette::Background, Qt::white);
    this->setAutoFillBackground(true);
    this->setPalette(Pal);
}

void QMapWidget::setSize(size_t size)
{
    _size = size;
    _robot = QPolygonF();
    _robot.append(QPointF(1.0,0.0)*size);
    _robot.append(QPointF(-0.5,-0.7)*size);
    _robot.append(QPointF(-0.25,0.0)*size);
    _robot.append(QPointF(-0.5,0.7)*size);
}

QVector3D QMapWidget::getPose()
{
    return _pose;
}

void QMapWidget::setPose(const QVector3D &pose)
{
    _pose = pose;
    repaint();
}

void QMapWidget::setOrientation(double orientation)
{
    _pose.setZ(orientation);
    repaint();
}

void QMapWidget::addPoint(const QPointF &point)
{
    _points.append(point);
    repaint();
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

void QMapWidget::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    painter.drawRect(rect());

    painter.translate(_center);
    painter.scale(1.0,-1.0);
    QTransform transform = QTransform::fromScale(_scale,_scale);

    painter.setPen(_point_pen);
    painter.drawPoints(transform.map(_points));

    painter.setPen(_robot_pen);
    painter.setBrush(_robot_brush);
    painter.drawPolygon(transform.rotateRadians(_pose.z()).map(_robot));
}
