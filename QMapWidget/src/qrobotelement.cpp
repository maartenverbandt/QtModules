#include "qrobotelement.h"

QRobotElement::QRobotElement(QObject *parent) : QPainterElement(parent)
{
    QPen pen;
    pen.setColor(Qt::black);
    pen.setWidth(2);
    setPen(pen);

    QBrush brush;
    brush.setColor(Qt::green);
    brush.setStyle(Qt::SolidPattern);
    setBrush(brush);

    setSize(1.0);
}

void QRobotElement::setSize(double size)
{
    if(size > 0.0){
        QPainterElement::setSize(size);
        _marker = QPolygonF();
        _marker.append(QPointF(1.0,0.0)*size);
        _marker.append(QPointF(-0.5,-0.7)*size);
        _marker.append(QPointF(-0.25,0.0)*size);
        _marker.append(QPointF(-0.5,0.7)*size);
    }
}

void QRobotElement::draw(QPainter &painter, QTransform transform)
{
    QPainterElement::draw(painter,transform);
    painter.drawPolygon(transform.map(_marker));
}
