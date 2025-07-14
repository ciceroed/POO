#include "cardgraphic.h"
#include "graphicitem.h"

CardGraphic::CardGraphic(const CardViewData& cardData, QGraphicsItem* parent):
    GraphicItem(cardData.spritePath, parent),
    _manaCost(cardData.manaCost),
    _title(cardData.title),
    _description(cardData.description)
{}

void CardGraphic::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    GraphicItem::paint(painter, option, widget);
}
