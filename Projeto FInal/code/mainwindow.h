#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QResizeEvent>

#include "game.h"

class QGraphicsScene;
class QGraphicsTextItem;

class GameView;
class GraphicItem;
class CharacterGraphic;
class CardGraphic;
class EndTurnButton;

class MainWindow : public QMainWindow {
    Q_OBJECT

private:
    GameView* _view;
    QGraphicsScene* _scene;

    Game _game;

    int _selectedCardId = -1;
    int _currentEnemyIndex;

    QGraphicsTextItem* _statusTextItem;
    EndTurnButton* _endTurnButton = nullptr;
    CharacterGraphic* _playerSprite = nullptr;
    QList<CharacterGraphic*> _mobSprites;
    QList<CardGraphic*> _handCardSprites;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void resizeEvent(QResizeEvent *event) override;

private:
    void updateLayout();
    void syncSceneWithGameState();
    void showTemporaryCard(const CardViewData& cardData, int durationMs);
    void showStatusMessage(const QString& message, int durationMs = 0);
    void hideStatusMessage();

public slots:
    void onCardClicked(int cardId);
    void onCharacterClicked(int targetId);

private slots:
    void onEndTurnButtonClicked();
    void processNextEnemyAction();


};

#endif // MAINWINDOW_H
