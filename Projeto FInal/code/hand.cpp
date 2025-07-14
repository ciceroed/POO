#include <iostream>

#include "hand.h"

Hand::Hand() {}

void Hand::selectCard(int index, Character& source, Character& target){

    if(index < 0 || index >= _cards.size()){
        std::cerr << "Erro: Índice de carta invalido!" << std::endl;
        return;
    }

    _cards[index]->cardEffect(source, target);

    _cards.erase(_cards.begin() + index);
}

void Hand::addCard(std::unique_ptr<Card> card){
    _cards.push_back(std::move(card));
}

std::vector<CardViewData> Hand::getCardsData(){

    std::vector<CardViewData> hand;

    for(const std::unique_ptr<Card>& card_ptr : _cards){
         CardViewData cardData;

        cardData.title = card_ptr->getTitle();
        cardData.description = card_ptr->getDescription();
        cardData.spritePath = card_ptr->getSpritePath();
        cardData.manaCost = card_ptr->getManaCost();

        hand.push_back(cardData);
    }

    return hand;
}
