//
// Created by jiaji on 2022/5/16.
//

#include "game_control.h"

void GameControl::start_turn() {
    using namespace std;
    this->player1->draw();
    this->player2->draw();
    int pl1 = select_card(*player1);
    int pl2 = select_card(*player2);
    Card *card1 = &(this->player1->hand[pl1]);
    Card *card2 = &(this->player2->hand[pl2]);
    card1->effect(*card2, *player1, *player2);
    card2->effect(*card1, *player2, *player1);
    judge(*card2, *card1);
    player1->play(pl1);
    player2->play(pl2);
}

void GameControl::judge(Card &card2, Card &card1) const {
    double power = (card2.power(card1) - card1.power(card2)) / 2;
    std::cout << player1->name << "'s card is:" << card1 << std::endl;
    std::cout << player1->name << "'s power is:" << card1.power(card2) << std::endl;
    std::cout << player2->name << "'s card is:" << card2 << std::endl;
    std::cout << player2->name << "'s power is:" << card2.power(card1) << std::endl;
    if (power > 0) {
        std::cout << player2->name << " wins!" << std::endl;
    } else if (power == 0) {
        std::cout << "No one wins!" << std::endl;
    } else {
        std::cout << player1->name << " wins!" << std::endl;
    }
}

int GameControl::select_card(Player &player) {
    using namespace std;
    cout << player.name << ", your cards are listed below:" << endl;
    player.displayHand();
    int a;
    cout << "Please enter the index of the card you want to draw!" << endl;
    cin >> a;
    return a;
}
