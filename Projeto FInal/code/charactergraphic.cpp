#include "charactergraphic.h"
#include "viewdata.h"

#include <QPainter>
#include <QDebug>

CharacterGraphic::CharacterGraphic(const CharacterViewData& characterData, QGraphicsItem* parent):
    GraphicItem(characterData.spritePath, parent),
    _name(characterData.name),
    _currentHealth(characterData.currentHealth),
    _maxHealth(characterData.maxHealth),
    _currentMana(characterData.currentMana),
    _maxMana(characterData.maxMana)
{}

void CharacterGraphic::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){

    GraphicItem::paint(painter, option, widget);

    float healthPercent = _currentHealth / (float)_maxHealth;
    QRectF healthBarRect(5, -15, boundingRect().width() - 10, 10);
    painter->setBrush(Qt::red);
    painter->drawRect(healthBarRect);
    painter->setBrush(Qt::green);
    painter->drawRect(healthBarRect.x(), healthBarRect.y(), healthBarRect.width()*healthPercent, healthBarRect.height());
}

