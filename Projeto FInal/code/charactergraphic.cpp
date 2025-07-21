#include "charactergraphic.h"
#include "viewdata.h"

#include <QPainter>
#include <QDebug>

CharacterGraphic::CharacterGraphic(const CharacterViewData& characterData, QGraphicsItem* parent):
    GraphicItem(characterData.spritePath, parent),
    _id(characterData.id),
    _name(characterData.name),
    _currentHealth(characterData.currentHealth),
    _maxHealth(characterData.maxHealth),
    _currentMana(characterData.currentMana),
    _maxMana(characterData.maxMana)
{}

QRectF CharacterGraphic::boundingRect() const{
    QRectF pixmapRect = _pixmap.rect();

    return QRectF(pixmapRect.x(), pixmapRect.y() - 50, pixmapRect.width(), pixmapRect.height() + 50);
}

void CharacterGraphic::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){

    GraphicItem::paint(painter, option, widget);

    float healthPercent = (_currentHealth > 0) ? _currentHealth / (float)_maxHealth : 0;
    QRectF healthBarRect(5, -15, boundingRect().width() - 10, 30);
    painter->setBrush(Qt::red);
    painter->drawRect(healthBarRect);
    painter->setBrush(Qt::green);
    painter->drawRect(healthBarRect.x(), healthBarRect.y(), healthBarRect.width()*healthPercent, healthBarRect.height());


    QString hpText = (_currentHealth > 0) ? QString::number(_currentHealth) + " / " + QString::number(_maxHealth) : "Dead";
    painter->setPen(Qt::white);
    painter->setFont(QFont("Arial", 24, QFont::Bold));
    painter->drawText(healthBarRect, Qt::AlignCenter, hpText);

    float manaPercent = _currentMana / (float)_maxMana;
    QRectF manaBarRect(5, 20, boundingRect().width() - 10, 20);
    painter->setBrush(Qt::darkBlue);
    painter->drawRect(manaBarRect);
    painter->setBrush(Qt::blue);
    painter->drawRect(manaBarRect.x(), manaBarRect.y(), manaBarRect.width()*manaPercent, manaBarRect.height());

    QString manaText = QString::number(_currentMana) + " / " + QString::number(_maxMana);
    painter->setPen(Qt::white);
    painter->setFont(QFont("Arial", 20, QFont::Bold));
    painter->drawText(manaBarRect, Qt::AlignCenter, manaText);
}


void CharacterGraphic::mousePressEvent(QGraphicsSceneMouseEvent *event){

    emit characterClicked(_id);
    GraphicItem::mousePressEvent(event);
}
