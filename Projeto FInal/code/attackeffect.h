#ifndef ATTACKEFFECT_H
#define ATTACKEFFECT_H

#include "icardeffect.h"
#include "character.h"

class AttackEffect : public ICardEffect
{
private:
    int _damage;
public:
    AttackEffect(int damage): _damage(damage){}

    void applyEffect(Character& source, Character& target) const override{
        target.setHealth(target.getHealth() - _damage);
    }
};

#endif // ATTACKEFFECT_H
