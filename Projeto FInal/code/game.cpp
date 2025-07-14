#include <iostream>

#include "game.h"
#include "character.h"
#include "attackeffect.h"
#include "card.h"
#include "deck.h"

using namespace std;

Game::Game(): _player("Herói", 60, 2, ":/images/characters/character-wizard.png") {

    _player.addCardToDeck(make_unique<Card>(2, "Bola de Fogo", "Causa 15 de dano à um alvo", make_unique<AttackEffect>(15), ":/images/cards/bola-de-fogo.png"));
    _player.addCardToDeck(make_unique<Card>(2, "Bola de Fogo", "Causa 15 de dano à um alvo", make_unique<AttackEffect>(15), ":/images/cards/bola-de-fogo.png"));
    _player.addCardToDeck(make_unique<Card>(2, "Bola de Fogo", "Causa 15 de dano à um alvo", make_unique<AttackEffect>(15), ":/images/cards/bola-de-fogo.png"));
    _player.addCardToDeck(make_unique<Card>(2, "Bola de Fogo", "Causa 15 de dano à um alvo", make_unique<AttackEffect>(15), ":/images/cards/bola-de-fogo.png"));
    _player.addCardToDeck(make_unique<Card>(2, "Bola de Fogo", "Causa 15 de dano à um alvo", make_unique<AttackEffect>(15), ":/images/cards/bola-de-fogo.png"));
    _player.addCardToDeck(make_unique<Card>(2, "Bola de Fogo", "Causa 15 de dano à um alvo", make_unique<AttackEffect>(15), ":/images/cards/bola-de-fogo.png"));
    _player.addCardToDeck(make_unique<Card>(2, "Bola de Fogo", "Causa 15 de dano à um alvo", make_unique<AttackEffect>(15), ":/images/cards/bola-de-fogo.png"));
    _player.addCardToDeck(make_unique<Card>(2, "Bola de Fogo", "Causa 15 de dano à um alvo", make_unique<AttackEffect>(15), ":/images/cards/bola-de-fogo.png"));
    _player.addCardToDeck(make_unique<Card>(2, "Bola de Fogo", "Causa 15 de dano à um alvo", make_unique<AttackEffect>(15), ":/images/cards/bola-de-fogo.png"));
    _player.addCardToDeck(make_unique<Card>(2, "Bola de Fogo", "Causa 15 de dano à um alvo", make_unique<AttackEffect>(15), ":/images/cards/bola-de-fogo.png"));

    _mobs.push_back(make_unique<Character>("Goblin", 20, 2, ":/images/characters/character-goblin.png"));
    _mobs.push_back(make_unique<Character>("Goblin", 20, 2, ":/images/characters/character-goblin.png"));

    for (const auto& mob_ptr : _mobs) {
        mob_ptr->addCardToDeck(make_unique<Card>(1, "Pancada", "Causa 5 de dano", make_unique<AttackEffect>(5), ":/images/cards/esgrima-goblin.png"));
    }

    _player.setInitialHand();
}

CharacterViewData Game::getPlayerViewData(){

    CharacterViewData playerCharacter;

    playerCharacter.name = _player.getCharacterName();
    playerCharacter.currentHealth = _player.getHealth();
    playerCharacter.currentMana = _player.getMana();
    playerCharacter.maxHealth = _player.getMaxHealth();
    playerCharacter.maxMana = _player.getMaxMana();
    playerCharacter.spritePath = _player.getCharacterSpritePath();

    return playerCharacter;
}

vector<CardViewData> Game::getPlayerHandData(){
    return _player.getHandData();
}

std::vector<CharacterViewData> Game::getMobsData(){

    std::vector<CharacterViewData> mobs;

    for(const std::unique_ptr<Character>& character_ptr : _mobs){
        CharacterViewData mobData;

        mobData.name = character_ptr->getCharacterName();
        mobData.currentHealth = character_ptr->getHealth();
        mobData.maxHealth = character_ptr->getMaxHealth();
        mobData.currentMana = character_ptr->getMana();
        mobData.maxMana = character_ptr->getMaxMana();
        mobData.spritePath = character_ptr->getCharacterSpritePath();

        mobs.push_back(mobData);
    }

    return mobs;
}
