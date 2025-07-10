#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

#include "deck.h"

using namespace std;

std::unique_ptr<Card> Deck::draw(){
    if(_cards.empty()){
        cerr << "Deck está vazio!" << endl;
        return nullptr;
    }
    std::unique_ptr<Card> tmp = std::move(_cards.back());
    _cards.pop_back();
    return tmp;
}

void Deck::shuffle(){
    random_device rd;
    mt19937 g(rd());
    std::shuffle(_cards.begin(), _cards.end(), g);
}

void Deck::addCard(std::unique_ptr<Card> card){
    _cards.push_back(std::move(card));
}

void Deck::removeCard(std::unique_ptr<Card> card){
    auto it = find(_cards.begin(), _cards.end(), card);
    if (it != _cards.end()) {
        _cards.erase(it);
    } else {
        cerr << "Carta não encontrada no deck!" << endl;
    }
}
