#ifndef ICARDEFFECT_H
#define ICARDEFFECT_H

class Character;

class ICardEffect
{
public:
    virtual void applyEffect(Character& source, Character& target) const = 0;
};

#endif // ICARDEFFECT_H
