#include "graphicitem.h"

#include <QPainter>
#include <QGraphicsSceneHoverEvent>
#include <QDebug>

GraphicItem::GraphicItem(const QString& resourcePath, QGraphicsItem* parent)
    : QGraphicsObject(parent), _isHovered(false) {

    if(!_pixmap.load(resourcePath)){
        qWarning() << "Falha ao carregar a imagem do recurso:" << resourcePath;
    }
    setAcceptHoverEvents(true);
}

QRectF GraphicItem::boundingRect() const{
    return _pixmap.rect();
}

void GraphicItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){

    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->drawPixmap(0, 0, _pixmap);

    if(_isHovered){
        painter->setBrush((QColor(255, 255, 0, 70)));
        painter->setPen(Qt::NoPen);
        painter->drawRect(boundingRect());
    }
}

void GraphicItem::hoverEnterEvent(QGraphicsSceneHoverEvent *event){

    _isHovered = true;
    update();
    QGraphicsObject::hoverEnterEvent(event);
}

void GraphicItem::hoverLeaveEvent(QGraphicsSceneHoverEvent *event){

    _isHovered = false;
    update();
    QGraphicsObject::hoverLeaveEvent(event);
}

