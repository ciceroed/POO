#include "mainwindow.h"
#include "game.h"
#include "graphicitem.h"
#include "charactergraphic.h"

#include <QDebug>
#include <QGraphicsView>
#include <QGraphicsScene>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {

    _scene = new QGraphicsScene(this);
    _view = new QGraphicsView(this);
    _view->setScene(_scene);
    setCentralWidget(_view);
    setWindowTitle("Castle Conquerors");
    resize(1920, 1080);

    _view->setRenderHint(QPainter::Antialiasing);

    CharacterGraphic* playerSprite = new CharacterGraphic(_game.getPlayerViewData());

    _scene->addItem(playerSprite);

    playerSprite->setPos(25,300);

    // GraphicItem* card1 = new GraphicItem("://images/cards/bola-de-fogo.png");
    // GraphicItem* card2 = new GraphicItem("://images/cards/esgrima-goblin.png");
    // GraphicItem* card3 = new GraphicItem("://images/cards/bola-de-fogo.png");

    // _scene->addItem(card1);
    // _scene->addItem(card2);
    // _scene->addItem(card3);

    // card1->setPos(50, 100);
    // card2->setPos(210,100);
    // card3->setPos(370,100);

    _scene->setSceneRect(0, 0, 1920, 1080);

    qDebug() << "Total de itens na cena:" << _scene->items().size();

    // Inicializamos nosso jogo aqui.
    // O construtor de _game já foi chamado na lista de inicialização.

    // Chamamos um método auxiliar para manter o construtor limpo
    //setupUI();

    // Agora que a UI está montada, podemos popular a cena com o estado inicial do jogo
    //_game.setupEncounter();
    //syncSceneWithGameState();
}

MainWindow::~MainWindow() {
    // Qt gerencia a memória dos widgets filhos automaticamente,
    // então o destrutor pode ficar vazio.
}
