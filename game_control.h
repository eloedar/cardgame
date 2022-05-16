#ifndef CARDGAME_GAME_CONTROL_H
#define CARDGAME_GAME_CONTROL_H

#include "player.h"

class GameControl {
private:
    Player *player1;
    Player *player2;
    std::vector<Card> deck1;
    std::vector<Card> deck2;
    static int turn_count;

public:
    GameControl(std::vector<Card> &deck1, std::vector<Card> &deck2, Player &player1, Player &player2) : player1(
            &player1), player2(&player2), deck2(deck2), deck1(deck1) {};

    void start_turn();

    int select_card(Player &player);

    void judge(Card &card2, Card &card1) const;
};

static int turn_count = 0;

#endif //CARDGAME_GAME_CONTROL_H
