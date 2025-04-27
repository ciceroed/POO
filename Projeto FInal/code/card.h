#ifndef CARD_H
#define CARD_H

#include <string>

using namespace std;

class Card
{
private:
    int _manaCost;
    string _title;
    string _description;

public:
    Card(int manaCost, string title, string description):
        _manaCost(manaCost),
        _title(title),
        _description(description){}

    int getManaCost(){
        return _manaCost;
    }
    string getDescription(){
        return _description;
    }
    string getTitle(){
        return _title;
    }
    virtual void cardEffect() = 0;
};

#endif // CARD_H
