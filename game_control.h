#ifndef CARDGAME_GAME_CONTROL_H
#define CARDGAME_GAME_CONTROL_H

#include "player.h"

class GameControl {
private:
    Player *player1;
    Player *player2;
    int scores_1;
    int scores_2;
    std::vector<Card *> deck1;
    std::vector<Card *> deck2;
//    static int turn_count;

public:
    GameControl(std::vector<Card *> &deck1, std::vector<Card *> &deck2, Player &player1, Player &player2) :
            player1(&player1), player2(&player2), deck2(deck2), deck1(deck1), scores_1(0), scores_2(0) {};

    void start_turn();

    void start_game(int count);

    static int select_card(Player &player);

    void judge(Card &card2, Card &card1);
};

//int GameControl::turn_count = 0;

#endif //CARDGAME_GAME_CONTROL_H
