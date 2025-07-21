#ifndef VIEWDATA_H
#define VIEWDATA_H

#include <QString>

struct CharacterViewData {
    int id;
    std::string name;
    int currentHealth;
    int maxHealth;
    int currentMana;
    int maxMana;
    QString spritePath;
};

struct CardViewData {
    int id;
    int manaCost;
    std::string title;
    std::string description;
    QString spritePath;
};

#endif // VIEWDATA_H
