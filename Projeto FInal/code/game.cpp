#include <iostream>
#include <QDebug>
#include <vector>

#include "game.h"
#include "character.h"
#include "attackeffect.h"
#include "card.h"
#include "deck.h"

using namespace std;

Game::Game(): _player("Herói", 60, 4, ":/images/characters/character-wizard.png"), _currentState(GameState::PLAYER_TURN) {

    for(int i = 0; i < 30; i++){
        _player.addCardToDeck(make_unique<Card>(2, "Bola de Fogo", "Causa 15 de dano à um alvo", make_unique<AttackEffect>(15), ":/images/cards/bola-de-fogo.png"));
    }

    _mobs.push_back(make_unique<Character>("Goblin", 60, 2, ":/images/characters/character-goblin.png"));
    _mobs.push_back(make_unique<Character>("Goblin", 60, 2, ":/images/characters/character-goblin.png"));

    for (const auto& mob_ptr : _mobs) {
        for(int i = 0; i < 30; i++){
            mob_ptr->addCardToDeck(make_unique<Card>(1, "Esgrima Goblin", "Causa 5 de dano", make_unique<AttackEffect>(5), ":/images/cards/esgrima-goblin.png"));
        }
    }

    _player.setInitialHand();
}

CharacterViewData Game::getPlayerViewData(){

    CharacterViewData playerCharacter;

    playerCharacter.id = _player.getCharacterId();
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

vector<CardViewData> Game::getMobHandData(int mobId){

    Character* mob = findCharacterById(mobId);

    if(mob == nullptr){
        qDebug() << "[Game] ERRO: Personagem com ID" << mobId << "não encontrada.";
        return {};
    }
    return mob->getHandData();

}
std::vector<CharacterViewData> Game::getMobsData(){

    std::vector<CharacterViewData> mobs;

    for(const std::unique_ptr<Character>& character_ptr : _mobs){
        CharacterViewData mobData;

        mobData.id = character_ptr->getCharacterId();
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

bool Game::cardRequiresTarget(int cardId, int characterId){

    Character* character = findCharacterById(characterId);

    if(character == nullptr){
        qDebug() << "[Game] ERRO: Personagem com ID" << characterId << "não encontrada.";
        return true;
    }

    return character->cardRequiresTarget(cardId);

}

void Game::playCard(int cardId, int targetId, int sourceId) {

    Character* source = findCharacterById(sourceId);
    Character* target = findCharacterById(targetId);

    if (targetId == -1) {
        target = source;
    }

    if (source == nullptr) {
        qDebug() << "[Game] ERRO: Fonte (source) com ID" << sourceId << "não encontrada.";
        return;
    }
    if (target == nullptr) {
        qDebug() << "[Game] ERRO: Alvo (target) com ID" << targetId << "não encontrado.";
        return;
    }
    if (source->getHealth() <= 0) {
        qDebug() << "[Game] Ação falhou: A fonte" << QString::fromStdString(source->getCharacterName()) << "está morta.";
        return;
    }
    if (target->getHealth() <= 0) {
        qDebug() << "[Game] Ação falhou: O alvo" << QString::fromStdString(target->getCharacterName()) << "já está morto.";
        return;
    }

    source->playCard(cardId, *target);

    cleanupDeadMobs();
    checkForGameOver();
}

void Game::startPlayerTurn(){
    cleanupDeadMobs();
    checkForGameOver();
    if (_currentState == GameState::ENEMY_TURN) {
        _player.restoreMana();
        _player.buyNewCard();
        _currentState = GameState::PLAYER_TURN;
    }
}

void Game::startMobsTurn(){

    if (_currentState == GameState::PLAYER_TURN) {
        for(std::unique_ptr<Character>& mob_ptr : _mobs){
            mob_ptr->restoreMana();
            mob_ptr->buyNewCard();
        }
        _currentState = GameState::ENEMY_TURN;
    }
}

Character* Game::findCharacterById(int characterId) {

    if (characterId == _player.getCharacterId()) {
        return &_player;
    }

    for (const auto& mob_ptr : _mobs) {
        if (characterId == mob_ptr->getCharacterId()) {
            return mob_ptr.get();
        }
    }

    return nullptr;
}

CardViewData Game::processNextMobAction(int mobId){

    Character* mob = findCharacterById(mobId);
    if (mob == nullptr) {
        qDebug() << "[Game] ERRO: Mob com ID" << mobId << "não encontrado para agir.";
        return {};
    }

    std::vector<CardViewData> mobHand = mob->getHandData();
    if (mobHand.empty()) {
        qDebug() << "[Game] IA Ação:" << QString::fromStdString(mob->getCharacterName()) << "não tem cartas para jogar.";
        return {};
    }
    CardViewData cardData = mobHand[0];

    if(mob->cardRequiresTarget(cardData.id)){
        playCard(cardData.id, _player.getCharacterId(), mob->getCharacterId());
    }
    else{
        playCard(cardData.id, -1, mob->getCharacterId());
    }

    return cardData;
}

void Game::cleanupDeadMobs(){

    std::erase_if(_mobs, [](const std::unique_ptr<Character>& mob){
        if(mob->getHealth() <= 0){
            return true;
        }
        return false;
    });
}

void Game::checkForGameOver(){
    if(_player.getHealth() <= 0) {
        qDebug() << "Fim de Jogo: O jogador foi derrotado";
        _currentState = GameState::PLAYER_DEFEAT;
        return;
    }

    if(_mobs.empty()){
        qDebug() << "Fim de Jogo: Vitória!";
        _currentState = GameState::PLAYER_VICTORY;
    }
}
