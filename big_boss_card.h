//
// Created by jiaji on 2022/5/16.
//

#ifndef CARDGAME_BIG_BOSS_CARD_H
#define CARDGAME_BIG_BOSS_CARD_H


#include "card.h"

#include <utility>

class BigBossCard: public Card{ ;

public:
    BigBossCard(std::string name, int attack, int defense) : Card(std::move(name), attack, defense) {}

    void effect(Card &opponentCard, Player &player, Player &opponent) override;
};

#endif //CARDGAME_BIG_BOSS_CARD_H
