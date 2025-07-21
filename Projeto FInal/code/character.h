#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <vector>
#include <memory>
#include <QString>
#include <QDebug>

#include "card.h"
#include "deck.h"
#include "hand.h"
#include "viewdata.h"

class Character
{
private:
    int _id;
    std::string _name;
    int _health;
    int _maxHealth;
    int _mana;
    int _maxMana;
    QString _spritePath;
    Hand _hand;
    std::unique_ptr<Deck> _deck; // Public atribute

    static int _nextId;
public:



    Character(std::string name, int health, int mana, QString spritePath):
        _name(name), _health(health), _maxHealth(health), _mana(mana), _maxMana(mana), _spritePath(spritePath), _deck(std::make_unique<Deck>()){
        _id = ++_nextId;
    }

    void setHealth(int health){
        _health = health;
    }
    void setMana(int mana){
        _mana = mana;
    }
    void setMaxHealth(int health){
        _maxHealth = health;
    }
    void setMaxMana(int mana){
        _maxMana = mana;
    }
    int getHealth(){
        return _health;
    }
    int getMana(){
        return _mana;
    }
    int getMaxHealth(){
        return _maxHealth;
    }
    int getMaxMana(){
        return _maxMana;
    }
    std::string getCharacterName(){
        return _name;
    }
    QString getCharacterSpritePath(){
        return _spritePath;
    }
    int getCharacterId(){
        return _id;
    }
    void restoreMana(){
        _mana = _maxMana;
    }
    void buyNewCard(){

        std::unique_ptr<Card> cardToDraw = _deck->draw();

        if(cardToDraw){
            _hand.addCard(std::move(cardToDraw));
        }

    }
    void setInitialHand(){
        for(int i = 5; i > 0; i--){
            buyNewCard();
        }
    }
    std::vector<CardViewData> getHandData(){
        return _hand.getCardsData();
    }

    void addCardToDeck(std::unique_ptr<Card> card){
        _deck->addCard(std::move(card));
    }

    void playCard(int cardId, Character& target){

        bool success = _hand.activateCard(cardId, *this, target);

        if(!success){
            qDebug() << "A tentativa de jogar a carta falhou.";
        }
    }

    void spendMana(int manaSpent){
        _mana -= manaSpent;
    }

    bool cardRequiresTarget(int cardId){
        return _hand.cardRequiresTarget(cardId);
    }
};

#endif // CHARACTER_H
