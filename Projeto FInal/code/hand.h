#ifndef HAND_H
#define HAND_H

#include <vector>

#include "card.h"
#include "viewdata.h"

class Hand
{
private:
    std::vector<std::unique_ptr<Card>> _cards;
    const size_t _maxCards = 6;
public:
    Hand();

    void addCard(std::unique_ptr<Card> card);
    bool activateCard(int cardId, Character& source, Character& target);
    std::vector<CardViewData> getCardsData();
    bool cardRequiresTarget(int cardId);
};

#endif // HAND_H
