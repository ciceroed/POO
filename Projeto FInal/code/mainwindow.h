#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "game.h"

class QGraphicsScene;
class QGraphicsView;

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QGraphicsView* _view;
    QGraphicsScene* _scene;
    Game _game;

    // void setupUI();
    // void syncSceneWithGameState();
};

#endif // MAINWINDOW_H
