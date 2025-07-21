#ifndef GRAPHICITEM_H
#define GRAPHICITEM_H

#include <QGraphicsItem>
#include <QPixmap>

class GraphicItem : public QGraphicsObject
{
    Q_OBJECT

public:
    GraphicItem(const QString& resourcePath, QGraphicsItem* parent = nullptr);

    QRectF boundingRect() const override;

    void paint(QPainter* painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

protected:

    void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

    QPixmap _pixmap;

private:
    bool _isHovered;
};

#endif // GRAPHICITEM_H
