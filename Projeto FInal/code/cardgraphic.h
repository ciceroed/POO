#ifndef CARDGRAPHIC_H
#define CARDGRAPHIC_H

#include "graphicitem.h"
#include "viewdata.h"

class CardGraphic : public GraphicItem
{
    Q_OBJECT

public:
    CardGraphic(const CardViewData& cardData, QGraphicsItem* parent = nullptr);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

signals:
    void cardClicked(int cardId);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

private:
    int _id;
    int _manaCost;
    std::string _title;
    std::string _description;
    QString _spritePath;
};

#endif // CARDGRAPHIC_H
