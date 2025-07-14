#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <QGraphicsView>

class GameView : public QGraphicsView
{
    Q_OBJECT

public:
    explicit GameView(QWidget *parent = nullptr);

protected:
    void drawBackground(QPainter* painter, const QRectF& rect) override;

private:
    QPixmap _backgroundPixmap;

};

#endif // GAMEVIEW_H
