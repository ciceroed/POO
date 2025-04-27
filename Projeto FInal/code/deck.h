#ifndef DECK_H
#define DECK_H

#include <vector>

#include "card.h"

using namespace std;

class Deck
{
private:
    vector<Card *> _cards;

public:
    Deck(vector<Card *> cards): _cards(cards){}

    Card* buyCard();
    void shuffle();
    void addCard(Card* card);
    void removeCard(Card* card);
    void printDeck();
};

#endif // DECK_H
