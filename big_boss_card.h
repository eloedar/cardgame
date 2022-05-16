//
// Created by jiaji on 2022/5/16.
//

#ifndef CARDGAME_BIG_BOSS_CARD_H
#define CARDGAME_BIG_BOSS_CARD_H


#include "card.h"

class BigBossCard: public Card{ ;

public:
    BigBossCard(std::string name, int attack, int defense) : Card(name, attack, defense) {}

    void effect(Card &opponentCard, Player &player, Player &opponent) override {
        int tmp = opponentCard.defense;
        opponentCard.defense = opponentCard.attack;
        opponentCard.attack = tmp;
    }
};


#endif //CARDGAME_BIG_BOSS_CARD_H
