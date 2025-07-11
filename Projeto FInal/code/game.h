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

};

#endif // GAME_H
