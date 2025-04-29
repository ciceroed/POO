#include <iostream>
#include <vector>

#include "card.h"
#include "damagecard.h"
#include "deck.h"
#include "defensecard.h"
#include "character.h"

using namespace std;

int main()
{
    DamageCard Fireball(4,
                    "Bola de Fogo",
                    "Conjura uma bola de fogo que queima os inimigos",
                    40);
    DamageCard Icebolt(3,
                    "Seta de Gelo",
                    "Conjura uma seta de gelo que congela os inimigos",
                    15);
    DamageCard MagicMissile(5,
                       "Misseis Mágicos",
                       "Conjura misseis mágicos que atingem os inimigos",
                       5);

    DefenseCard Shield(3,
                       "Escudo",
                       "Concede escudo ao usuário",
                       10);

    cout << "Custo de Mana: " << Shield.getManaCost() << endl;
    cout << "Título: " << Shield.getTitle() << endl;
    cout << "Descrição: " << Shield.getDescription() << endl;

    Shield.cardEffect();

    vector <Card *> d = {&Fireball, &Icebolt, &Shield};

    Deck deck(d);

    deck.printDeck();

    cout << "Add card" << endl;
    deck.addCard(&MagicMissile);

    deck.printDeck();

    cout << "Remove card" << endl;
    deck.removeCard(&MagicMissile);

    deck.printDeck();
/*
    Card* buyCard = deck.buyCard();

    buyCard->cardEffect();

    deck.printDeck();

    buyCard = deck.buyCard();

    buyCard->cardEffect();

    deck.printDeck();

    buyCard = deck.buyCard(); */
}
