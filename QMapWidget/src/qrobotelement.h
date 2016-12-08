#ifndef QROBOTELEMENT_H
#define QROBOTELEMENT_H

#include <qpainterelement.h>

class QRobotElement : public QPainterElement
{
public:
    QRobotElement(QObject *parent = 0);

    void setSize(double size);
    void draw(QPainter &painter, QTransform transform = QTransform());

private:
    QPolygonF _marker;


};

#endif // QROBOTELEMENT_H
