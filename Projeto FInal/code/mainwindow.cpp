#include "mainwindow.h"
#include "game.h"
#include "graphicitem.h"
#include "charactergraphic.h"
#include "cardgraphic.h"
#include "gameview.h"
#include "endturnbutton.h"

#include <QDebug>
#include <QGraphicsScene>
#include <QTimer>
#include <QGraphicsTextItem>
#include <QString>

#define TIMER_INTERVAL      1000

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), _playerSprite(nullptr) {

    _scene = new QGraphicsScene(this);
    _view = new GameView(this);
    _view->setScene(_scene);
    setCentralWidget(_view);
    setWindowTitle("Castle Conquerors");
    resize(1920, 1080);

    _endTurnButton = new EndTurnButton(":/images/assets/fim-de-turno.png");
    _scene->addItem(_endTurnButton);
    connect(_endTurnButton, &EndTurnButton::clicked, this, &MainWindow::onEndTurnButtonClicked);

    _statusTextItem = new QGraphicsTextItem();
    _scene->addItem(_statusTextItem);
    _statusTextItem->setFont(QFont("Arial", 24, QFont::Bold));
    _statusTextItem->setDefaultTextColor(Qt::yellow);
    _statusTextItem->setZValue(100);
    _statusTextItem->setVisible(false);

    _view->setRenderHint(QPainter::Antialiasing);

    syncSceneWithGameState();

    _scene->setSceneRect(0, 0, 1920, 1080);

    qDebug() << "Total de itens na cena:" << _scene->items().size();
}

void MainWindow::onCardClicked(int cardId){

    qDebug() << "Slot: Carta com ID " << cardId << "foi clicada.";

    if(_game.cardRequiresTarget(cardId, _playerSprite->getCharacterId())){
        qDebug() << "Aguardando seleção de alvo...";
        showStatusMessage("Aguardando seleção de alvo...");
        _selectedCardId = cardId;
    }
    else{
        qDebug() << "Jogando carta sem alvo...";
        _game.playCard(cardId, -1, _playerSprite->getCharacterId());
        syncSceneWithGameState();
    }
}

void MainWindow::onCharacterClicked(int targetId){

    if(_selectedCardId == -1) {
        return;
    }

    hideStatusMessage();

    _game.playCard(_selectedCardId, targetId, _playerSprite->getCharacterId());

    _selectedCardId = -1;

    syncSceneWithGameState();
}
void MainWindow::updateLayout(){

    QSize viewSize = _view->size();
    const int margin = 20;
    const int characterMarginY = 260;

    if (_endTurnButton) {

        QSizeF buttonSize = _endTurnButton->boundingRect().size();

        float buttonX = viewSize.width() - buttonSize.width() - margin;

        float buttonY = viewSize.height() - buttonSize.height() - margin;

        _endTurnButton->setPos(buttonX, buttonY);
    }

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

void MainWindow::syncSceneWithGameState(){

    for (CardGraphic* card : _handCardSprites) {
        card->deleteLater();
    }
    for (CharacterGraphic* mob : _mobSprites) {
        mob->deleteLater();
    }

    if (_playerSprite) {
        _playerSprite->deleteLater();
    }

    _handCardSprites.clear();
    _mobSprites.clear();
    _playerSprite = nullptr;

    GameState currentState = _game.getGameState();

    if (currentState == GameState::PLAYER_VICTORY) {
        QGraphicsTextItem* victoryText = new QGraphicsTextItem("VOCÊ VENCEU!");
        victoryText->setFont(QFont("Arial", 50, QFont::Bold));
        victoryText->setDefaultTextColor(Qt::yellow);
        victoryText->setPos( (width() - victoryText->boundingRect().width()) / 2,
                            (height() - victoryText->boundingRect().height()) / 2 );
        _scene->addItem(victoryText);
        _endTurnButton->setEnabled(false);
        return;
    }
    else if (currentState == GameState::PLAYER_DEFEAT) {
        QGraphicsTextItem* defeatText = new QGraphicsTextItem("VOCÊ FOI DERROTADO!");
        defeatText->setFont(QFont("Arial", 50, QFont::Bold));
        defeatText->setDefaultTextColor(Qt::yellow);
        defeatText->setPos( (width() - defeatText->boundingRect().width()) / 2,
                            (height() - defeatText->boundingRect().height()) / 2 );
        _scene->addItem(defeatText);
        _endTurnButton->setEnabled(false);
        return;
    }
    else if (currentState == GameState::PLAYER_TURN) {
        _endTurnButton->setEnabled(true);
        _endTurnButton->setOpacity(1.0);
    } else {
        _endTurnButton->setEnabled(false);
        _endTurnButton->setOpacity(0.5);
    }

    _playerSprite = new CharacterGraphic(_game.getPlayerViewData());
    _scene->addItem(_playerSprite);
    connect(_playerSprite, &CharacterGraphic::characterClicked, this, &MainWindow::onCharacterClicked);


    std::vector<CharacterViewData> mobsData = _game.getMobsData();
    for(CharacterViewData& mobData : mobsData){

        CharacterGraphic* newMobSprite = new CharacterGraphic(mobData);
        _mobSprites.append(newMobSprite);
        _scene->addItem(newMobSprite);
        connect(newMobSprite, &CharacterGraphic::characterClicked, this, &MainWindow::onCharacterClicked);
    }


    std::vector<CardViewData> playerHandData = _game.getPlayerHandData();
    for(CardViewData& cardData : playerHandData){

        CardGraphic* newCardSprite = new CardGraphic(cardData);
        _handCardSprites.append(newCardSprite);
        _scene->addItem(newCardSprite);
        connect(newCardSprite, &CardGraphic::cardClicked, this, &MainWindow::onCardClicked);
    }

    updateLayout();
}

void MainWindow::resizeEvent(QResizeEvent *event){
    updateLayout();

    QMainWindow::resizeEvent(event);
}

void MainWindow::onEndTurnButtonClicked(){
    qDebug() << "Fim do turno do jogador";
    _currentEnemyIndex = 0;
    _game.startMobsTurn();
    syncSceneWithGameState();
    QTimer::singleShot(TIMER_INTERVAL, this, SLOT(processNextEnemyAction()));
}

void MainWindow::processNextEnemyAction(){
    if(_currentEnemyIndex >= _mobSprites.size()){
        qDebug() << "Fim do turno dos inimigos";
        _game.startPlayerTurn();
        syncSceneWithGameState();
        return;
    }

    int mobId = _mobSprites[_currentEnemyIndex]->getCharacterId();
    CardViewData playedCard = _game.processNextMobAction(mobId);

    QString message = QString("%1 utilizou a carta %2")
                          .arg(QString::fromStdString(_mobSprites[_currentEnemyIndex]->getCharacterName()))
                          .arg(QString::fromStdString(playedCard.title));
    showStatusMessage(message, TIMER_INTERVAL*0.8);

    showTemporaryCard(playedCard, TIMER_INTERVAL*0.8);

    qDebug() << mobId << "utilizou a carta " << playedCard.title;
    syncSceneWithGameState();
    _currentEnemyIndex++;
    QTimer::singleShot(TIMER_INTERVAL, this, SLOT(processNextEnemyAction()));
}

void MainWindow::showTemporaryCard(const CardViewData& cardData, int durationMs) {

    CardGraphic* tempCardSprite = new CardGraphic(cardData);

    _scene->addItem(tempCardSprite);

    QSize viewSize = _view->size();
    QRectF cardRect = tempCardSprite->boundingRect();
    float cardX = (viewSize.width() - cardRect.width()) / 2.0f;
    float cardY = (viewSize.height() - cardRect.height()) / 2.0f;
    tempCardSprite->setPos(cardX, cardY);
    tempCardSprite->setZValue(200);

    QTimer::singleShot(durationMs, this, [tempCardSprite](){
        if (tempCardSprite) {
            tempCardSprite->deleteLater();
        }
    });
}

void MainWindow::showStatusMessage(const QString& message, int durationMs) {
    _statusTextItem->setPlainText(message);

    QRectF textRect = _statusTextItem->boundingRect();
    QSize viewSize = _view->size();
    float textX = (viewSize.width() - textRect.width()) / 2.0f;
    float textY = 30;
    _statusTextItem->setPos(textX, textY);

    _statusTextItem->setVisible(true);

    if (durationMs > 0) {
        QTimer::singleShot(durationMs, this, [this](){
            hideStatusMessage();
        });
    }
}

void MainWindow::hideStatusMessage() {
    _statusTextItem->setVisible(false);
}


MainWindow::~MainWindow() {}
