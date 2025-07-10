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
