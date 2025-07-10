#ifndef DECK_H
#define DECK_H

#include <vector>

#include "card.h"

class Deck
{
private:
    std::vector<std::unique_ptr<Card>> _cards;

public:
    Deck(){}
    Deck(std::vector<std::unique_ptr<Card>> cards): _cards(std::move(cards)){}

    std::unique_ptr<Card> draw();
    void shuffle();
    void addCard(std::unique_ptr<Card> card);
    void removeCard(std::unique_ptr<Card> card);
};

#endif // DECK_H
