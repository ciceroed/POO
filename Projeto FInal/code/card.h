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
    int _manaCost;
    std::string _title;
    std::string _description;
    std::unique_ptr<ICardEffect> _effect;
    QString _spritePath;

public:
    Card(int manaCost, std::string title, std::string description, std::unique_ptr<ICardEffect> effect, QString spritePath):
        _manaCost(manaCost),
        _title(title),
        _description(description),
        _effect(std::move(effect)),
        _spritePath(spritePath){}

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
};

#endif // CARD_H
