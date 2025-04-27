#ifndef DAMAGECARD_H
#define DAMAGECARD_H

#include <iostream>
#include <string>

#include "card.h"

class DamageCard : public Card
{
private:
    int _damage;

public:
    DamageCard(int manaCost, string title, string description, int damage):
        Card(manaCost, title, description),
        _damage(damage){}

    void cardEffect() override {
        cout << this->getTitle() << "causa " << _damage << " de dano!" << endl;
    }
};

#endif // DAMAGECARD_H
