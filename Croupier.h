//
// Created by jiaji on 2022/5/29.
//

#ifndef CARDGAME_CROUPIER_H
#define CARDGAME_CROUPIER_H

#include "player.h"
#include "big_boss_card.h"
#include "exchange_card.h"


class Croupier {
private:
    Player player1;
    Player player2;
    std::vector<Card*> deck1;
    std::vector<Card*> deck2;
    Card card;
    BigBossCard bigBossCard;
    ExchangeCard exchangeCard;

    int Card_num = 5;
    int BigBossCard_num = 1;
    int ExchangeCard_num = 2;
public:
    Croupier(Player &player1, Player &player2, int Card_num = 5, int BigBossCard_num = 1, int ExchangeCard_num = 2);

    void DeckGenerator();

    void DeckShuffle();

    void ArgumentSetter(int bigBossCard_num, int exchangeCard_num, int Card_num);
};


#endif //CARDGAME_CROUPIER_H
