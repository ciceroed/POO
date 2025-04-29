#ifndef CHARACTER_H
#define CHARACTER_H

#include "deck.h"

class Character
{
private:
    int _health;
    int _mana;
    Deck _deck;
public:
    Character(int health, int mana, Deck deck):
        _health(health), _mana(mana), _deck(deck){}

    void setHealth(int health){
        _health = health;
    }
    void setMana(int mana){
        _mana = mana;
    }
    int getHealth(){
        return _health;
    }
    int getMana(){
        return _mana;
    }

    Deck getDeck(){
        return _deck;
    }
};

#endif // CHARACTER_H
