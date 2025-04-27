#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

#include "deck.h"

Card* Deck::buyCard(){
    if(_cards.empty()){
        cout << "Deck está vazio!" << endl;
        return nullptr;
    }
    Card* tmp = _cards.back();
    _cards.pop_back();
    return tmp;
}

void Deck::shuffle(){
    random_device rd;
    mt19937 g(rd());
    std::shuffle(_cards.begin(), _cards.end(), g);
}

void Deck::addCard(Card* card){
    _cards.push_back(card);
}

void Deck::removeCard(Card* card){
    auto it = find(_cards.begin(), _cards.end(), card);
    if (it != _cards.end()) {
        _cards.erase(it);
    } else {
        cout << "Carta não encontrada no deck!" << endl;
    }
}

void Deck::printDeck(){
    for(int i=0; i < (int)_cards.size(); i++){
        cout << _cards[i]->getTitle() << endl;
    }
}
