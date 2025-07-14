#ifndef CHARACTERGRAPHIC_H
#define CHARACTERGRAPHIC_H

#include "graphicitem.h"
#include "viewdata.h"

class CharacterGraphic : public GraphicItem
{
    Q_OBJECT
public:
    CharacterGraphic(const CharacterViewData& characterData, QGraphicsItem* parent = nullptr);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    QRectF boundingRect() const override;

private:
    std::string _name;
    int _currentHealth;
    int _maxHealth;
    int _currentMana;
    int _maxMana;
};

#endif // CHARACTERGRAPHIC_H
