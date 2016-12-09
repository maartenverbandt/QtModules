#ifndef QARROWELEMENT_H
#define QARROWELEMENT_H

#include <qpainterelement.h>

class QArrowElement : public QPainterElement
{
public:
    QArrowElement(QObject *parent = 0);

    void setSize(double size);
    void draw(QPainter &painter, QTransform transform);

private:
    QPolygonF _arrow;

};

#endif // QARROWELEMENT_H
