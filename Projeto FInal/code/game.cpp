#include <iostream>

#include "game.h"
#include "character.h"
#include "attackeffect.h"
#include "card.h"
#include "deck.h"

using namespace std;

Game::Game(): _player("Herói", 60, 2) {

    _player.addCardToDeck(make_unique<Card>(2, "Bola de Fogo", "Causa 15 de dano à um alvo", make_unique<AttackEffect>(15)));
    _player.addCardToDeck(make_unique<Card>(2, "Bola de Fogo", "Causa 15 de dano à um alvo", make_unique<AttackEffect>(15)));

    _mobs.push_back(make_unique<Character>("Goblin", 20, 2));
    _mobs.push_back(make_unique<Character>("Goblin", 20, 2));

    for (const auto& mob_ptr : _mobs) {
        mob_ptr->addCardToDeck(make_unique<Card>(1, "Pancada", "Causa 5 de dano", make_unique<AttackEffect>(5)));
    }

    _player.setInitialHand();
}
