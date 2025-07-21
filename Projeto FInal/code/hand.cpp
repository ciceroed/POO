#include <iostream>
#include <QDebug>

#include "hand.h"
#include "character.h"

Hand::Hand(){}

bool Hand::activateCard(int cardId, Character& source, Character& target){

    for(auto it = _cards.begin(); it != _cards.end(); ++it){
        if(cardId == (*it)->getCardId()){

            int manaCost = (*it)->getManaCost();
            if(source.getMana() < manaCost){
                qDebug() << "Mana insuficiente!";
                return false;
            }

            (*it)->cardEffect(source, target);

            source.spendMana(manaCost);

            _cards.erase(it);

            qDebug() << "Carta com ID " << cardId << "jogada e removida da mão";
            return true;
        }
    }

    qDebug() << "Tentativa de jogar carta com ID << " << cardId << " terminou com falha.";
    return false;
}

bool Hand::cardRequiresTarget(int cardId){
    for(std::unique_ptr<Card>& card_ptr : _cards){
        if(cardId == card_ptr->getCardId()){
            return card_ptr->cardRequiresTarget();
        }
    }

    qDebug() << "Hand::cardRequiresTarget não encontrou o target";
    return true;
}

void Hand::addCard(std::unique_ptr<Card> card){
    _cards.push_back(std::move(card));

    if (_cards.size() > _maxCards){
        _cards.erase(_cards.begin());
    }
}

std::vector<CardViewData> Hand::getCardsData(){

    std::vector<CardViewData> hand;

    for(const std::unique_ptr<Card>& card_ptr : _cards){
         CardViewData cardData;

        cardData.id = card_ptr->getCardId();
        cardData.title = card_ptr->getTitle();
        cardData.description = card_ptr->getDescription();
        cardData.spritePath = card_ptr->getSpritePath();
        cardData.manaCost = card_ptr->getManaCost();

        hand.push_back(cardData);
    }

    return hand;
}
