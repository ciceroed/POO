#ifndef GAME_H
#define GAME_H

#include <vector>

#include "viewdata.h"
#include "character.h"


class Game
{
    Character _player;
    std::vector<std::unique_ptr<Character>> _mobs;

public:
    Game();

    CharacterViewData getPlayerViewData();
    std::vector<CardViewData> getPlayerHandData();
    std::vector<CharacterViewData> getMobsData();

};

#endif // GAME_H
