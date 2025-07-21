#include "endturnbutton.h"

EndTurnButton::EndTurnButton(const QString& imagePath, QGraphicsItem* parent):
    GraphicItem(imagePath, parent){}


void EndTurnButton::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    emit clicked();
    GraphicItem::mousePressEvent(event);
}
