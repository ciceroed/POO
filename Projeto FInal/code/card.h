#ifndef CARD_H
#define CARD_H

#include <string>
#include <memory>

#include "icardeffect.h"

class Character;

class Card
{
private:
    int _manaCost;
    std::string _title;
    std::string _description;
    std::unique_ptr<ICardEffect> _effect;

public:
    Card(int manaCost, std::string title, std::string description, std::unique_ptr<ICardEffect> effect):
        _manaCost(manaCost),
        _title(title),
        _description(description),
        _effect(std::move(effect)){}

    int getManaCost(){
        return _manaCost;
    }
    std::string getDescription(){
        return _description;
    }
    std::string getTitle(){
        return _title;
    }
    void cardEffect(Character& source, Character& target){
        _effect->applyEffect(source, target);
    }
};

#endif // CARD_H
