#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QResizeEvent>

#include "game.h"

class QGraphicsScene;

class GameView;
class GraphicItem;
class CharacterGraphic;
class CardGraphic;

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void resizeEvent(QResizeEvent *event) override;

private:
    void updateLayout();

    GameView* _view;
    QGraphicsScene* _scene;
    Game _game;


    CharacterGraphic* _playerSprite;
    QList<CharacterGraphic*> _mobSprites;
    QList<CardGraphic*> _handCardSprites;
};

#endif // MAINWINDOW_H
