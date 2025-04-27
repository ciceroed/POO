#include "mainwindow.h"

#include <string>

#include <QApplication>

using namespace std;

class Card{
private:
    int _manaCost;
    string _title;
    string _description;
public:
};

class Deck{
private:
    vector<Card*> _cards;
public:
};

class Character{
private:
    int _healthPoints;
    int _mana;
    Deck _deck;
public:
    Character(int hp = 50, int mana = 10): _healthPoints(hp), _mana(mana){}
};

int main()
{
    Character player;
}
