#include "gameview.h"

#include <QPainter>

GameView::GameView(QWidget* parent) : QGraphicsView(parent) {

    _backgroundPixmap.load(":/images/backgrounds/goblin-cave.png");
}

void GameView::drawBackground(QPainter *painter, const QRectF &rect){

    QGraphicsView::drawBackground(painter, rect);

    painter->drawPixmap(rect, _backgroundPixmap, _backgroundPixmap.rect());

}
