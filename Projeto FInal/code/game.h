#ifndef GAME_H
#define GAME_H

#include <vector>

#include "viewdata.h"
#include "character.h"

enum class GameState{
    PLAYER_TURN,
    ENEMY_TURN,
    PLAYER_VICTORY,
    PLAYER_DEFEAT
};

class Game
{
    Character _player;
    std::vector<std::unique_ptr<Character>> _mobs;
    GameState _currentState;

public:
    Game();

    // Player related
    CharacterViewData getPlayerViewData();
    std::vector<CardViewData> getPlayerHandData();
    void startPlayerTurn();

    // Mob related
    std::vector<CharacterViewData> getMobsData();
    std::vector<CardViewData> getMobHandData(int mobId);
    void startMobsTurn();
    CardViewData processNextMobAction(int mobVectorIndex);

    // Card related
    bool cardRequiresTarget(int cardId, int characterId);
    void playCard(int cardId, int targetId, int sourceId);

    // Overall game related
    void checkForGameOver();
    void cleanupDeadMobs();
    GameState getGameState(){
        return _currentState;
    }

private:
    Character* findCharacterById(int characterId);
};

#endif // GAME_H
