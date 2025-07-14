#ifndef HAND_H
#define HAND_H

#include <vector>

#include "card.h"
#include "viewdata.h"

class Hand
{
private:
    std::vector<std::unique_ptr<Card>> _cards;
public:
    Hand();

    void addCard(std::unique_ptr<Card> card);
    void selectCard(int index, Character& source, Character& target);
    std::vector<CardViewData> getCardsData();
};

#endif // HAND_H
