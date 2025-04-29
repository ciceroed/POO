#ifndef DEFENSECARD_H
#define DEFENSECARD_H

#include <string>
#include <iostream>

#include "card.h"

class DefenseCard: public Card
{
private:
    int _shield;
public:
    DefenseCard(int manaCost, string title, string description, int shield):
        Card(manaCost, title, description),
        _shield(shield){}

    void cardEffect() override{
        cout << this->getTitle() << " concede " << _shield << " de escudo!" << endl;
    }
};

#endif // DEFENSECARD_H
