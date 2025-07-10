#ifndef CARDITEM_H
#define CARDITEM_H

#include <QGraphicsItem>
#include <QPixmap>

class CardItem : public QGraphicsObject
{
    Q_OBJECT

public:
    CardItem(const QString& resourcePath, QGraphicsItem* parent = nullptr);

    QRectF boundingRect() const override;

    void paint(QPainter* painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

protected:

    void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

private:
    QPixmap _pixmap;
    bool _isHovered;
};

#endif // CARDITEM_H
