#include "carditem.h"

#include <QPainter>
#include <QGraphicsSceneHoverEvent>
#include <QDebug>

CardItem::CardItem(const QString& resourcePath, QGraphicsItem* parent)
    : QGraphicsObject(parent), _isHovered(false) {

    if(!_pixmap.load(resourcePath)){
        qWarning() << "Falha ao carregar a imagem do recurso:" << resourcePath;
    }
    setAcceptHoverEvents(true);
}

QRectF CardItem::boundingRect() const{
    return _pixmap.rect();
}

void CardItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){

    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->drawPixmap(0, 0, _pixmap);

    if(_isHovered){
        painter->setBrush((QColor(255, 255, 0, 80)));
        painter->setPen(Qt::NoPen);
        painter->drawRect(boundingRect());
    }
}

void CardItem::hoverEnterEvent(QGraphicsSceneHoverEvent *event){

    _isHovered = true;
    update();
    QGraphicsObject::hoverEnterEvent(event);
}

void CardItem::hoverLeaveEvent(QGraphicsSceneHoverEvent *event){

    _isHovered = false;
    update();
    QGraphicsObject::hoverLeaveEvent(event);
}

void CardItem::mousePressEvent(QGraphicsSceneMouseEvent *event){

    // Aqui você emitiria um sinal para a MainWindow saber que esta carta foi clicada
    // emit cardClicked(this);
    QGraphicsObject::mousePressEvent(event);
}
