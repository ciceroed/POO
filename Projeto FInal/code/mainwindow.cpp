#include "mainwindow.h"
#include "game.h"
#include "graphicitem.h"
#include "charactergraphic.h"
#include "cardgraphic.h"
#include "gameview.h"

#include <QDebug>
#include <QGraphicsScene>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {

    _scene = new QGraphicsScene(this);
    _view = new GameView(this);
    _view->setScene(_scene);
    setCentralWidget(_view);
    setWindowTitle("Castle Conquerors");
    resize(1920, 1080);

    _view->setRenderHint(QPainter::Antialiasing);

    _playerSprite = new CharacterGraphic(_game.getPlayerViewData());

    _scene->addItem(_playerSprite);

    std::vector<CharacterViewData> mobsData = _game.getMobsData();

    for(CharacterViewData& mobData : mobsData){

        CharacterGraphic* newMobSprite = new CharacterGraphic(mobData);
        _mobSprites.append(newMobSprite);
        _scene->addItem(newMobSprite);
    }

    std::vector<CardViewData> playerHandData = _game.getPlayerHandData();

    for(CardViewData& cardData : playerHandData){

        CardGraphic* newCardSprite = new CardGraphic(cardData);
        _handCardSprites.append(newCardSprite);
        _scene->addItem(newCardSprite);
    }

    updateLayout();

    _scene->setSceneRect(0, 0, 1920, 1080);

    qDebug() << "Total de itens na cena:" << _scene->items().size();
}

void MainWindow::updateLayout(){

    QSize viewSize = _view->size();
    const int margin = 20;
    const int characterMarginY = 260;

    if(_playerSprite) {
        float playerY = viewSize.height() - _playerSprite->boundingRect().height() - characterMarginY;
        _playerSprite->setPos(margin, playerY);
    }

    for(int i = 0; i < _mobSprites.size(); ++i){
        CharacterGraphic* mobSprite = _mobSprites[i];

        const float mobWidth = mobSprite->boundingRect().width();
        float mobY = viewSize.height() - mobSprite->boundingRect().height() - characterMarginY;
        float mobX = viewSize.width() - mobWidth - margin - (i * (mobWidth + 10));

        mobSprite->setPos(mobX, mobY);
    }

    if(_handCardSprites.isEmpty()) return;

    const float cardWidth = _handCardSprites.first()->boundingRect().width();
    const float cardSpacing = 20;
    const float handBottomMargin = margin;

    const float totalHandWidth = (_handCardSprites.size() * cardWidth) + ((_handCardSprites.size() - 1) * cardSpacing);

    float startX = (viewSize.width() - totalHandWidth) / 2.0f;

    float cardY = viewSize.height() - _handCardSprites.first()->boundingRect().height() - handBottomMargin;

    for(int i = 0; i < _handCardSprites.size(); ++i) {
        CardGraphic* card = _handCardSprites[i];
        float currentX = startX + i * (cardWidth + cardSpacing);
        card->setPos(currentX, cardY);
    }
}

void MainWindow::resizeEvent(QResizeEvent *event){
    updateLayout();

    QMainWindow::resizeEvent(event);
}

MainWindow::~MainWindow() {}
