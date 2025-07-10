#ifndef GAME_H
#define GAME_H

#include <vector>

#include "character.h"

class Game
{
    Character _player;
    std::vector<std::unique_ptr<Character>> _mobs;

public:
    Game();

    int getPlayerHealth();
    int getPlayerMana();
    int getMobHealth();
    int getMobMana();

    bool canPlayCard();

};

#endif // GAME_H
