#ifndef CARD_H
#define CARD_H

#include <string>
#include <memory>
#include <QString>

#include "icardeffect.h"

class Character;

class Card
{
private:
    int _id;
    int _manaCost;
    std::string _title;
    std::string _description;
    std::unique_ptr<ICardEffect> _effect;
    QString _spritePath;

    static int _nextId;

public:
    Card(int manaCost, std::string title, std::string description, std::unique_ptr<ICardEffect> effect, QString spritePath):
        _manaCost(manaCost),
        _title(title),
        _description(description),
        _effect(std::move(effect)),
        _spritePath(spritePath){

        _id = _nextId++;
    }

    int getCardId(){
        return _id;
    }
    int getManaCost(){
        return _manaCost;
    }
    std::string getDescription(){
        return _description;
    }
    std::string getTitle(){
        return _title;
    }
    QString getSpritePath(){
        return _spritePath;
    }
    void cardEffect(Character& source, Character& target){
        _effect->applyEffect(source, target);
    }
    bool cardRequiresTarget(){
        return _effect->requiresTarget();
    }
};

#endif // CARD_H
