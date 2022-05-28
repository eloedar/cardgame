//
// Created by jiaji on 2022/5/16.
//

#include "game_control.h"

int GameControl::turn_count = 0;

void GameControl::start_turn() {
    using namespace std;
    this->player1->draw();
    this->player2->draw();
    int pl1 = select_card(*player1);
    int pl2 = select_card(*player2);
    Card *card1 = &(player1->play(pl1));
    Card *card2 = &(player2->play(pl2));
    card1->effect(*card2, *player1, *player2);
    card2->effect(*card1, *player2, *player1);
    judge(*card2, *card1);
    player1->hand.erase(player1->hand.begin() + pl1);
    player2->hand.erase(player2->hand.begin() + pl2);
    turn_count++;
}

void GameControl::judge(Card &card2, Card &card1) {
    double power = (card2.power(card1) - card1.power(card2)) / 2;
    std::cout << player1->name << "'s card is:" << card1 << std::endl;
    std::cout << player1->name << "'s power is:" << card1.power(card2) << std::endl;
    std::cout << player2->name << "'s card is:" << card2 << std::endl;
    std::cout << player2->name << "'s power is:" << card2.power(card1) << std::endl;
    if (power > 0) {
        std::cout << player2->name << " wins!" << std::endl;
        scores_2++;
    } else if (power == 0) {
        std::cout << "No one wins!" << std::endl;
    } else {
        std::cout << player1->name << " wins!" << std::endl;
        scores_1++;
    }
}

int GameControl::select_card(Player &player) {
    using namespace std;
    cout << player.name << ", your cards are listed below:" << endl;
    player.displayIndexedHand();
    int a;
    cout << "Please enter the index of the card you want to draw!" << endl;
    if ((cin >> a) && (a >= 0) && (a < player.hand.size())) {
        return a;
    } else {
        cout << "Invalid input!" << endl;
        return select_card(player);
    }
}

void GameControl::start_game(int const count) {
    for (int i = 0; count > turn_count; ++i) {
        start_turn();
        if (player1->hand.empty() || player2->hand.empty()) { break; }
    }
    if (scores_1 > scores_2) {
        std::cout << player2->name << " wins the whole game!" << std::endl;
        std::cout << player1->name << "'s score is: " << this->scores_1 << std::endl;
        std::cout << player2->name << "'s score is: " << this->scores_2 << std::endl;
    } else if (scores_1 == scores_2) {
        std::cout << "No one wins! You both equal!" << std::endl;
        std::cout << player1->name << "'s score is: " << this->scores_1 << std::endl;
        std::cout << player2->name << "'s score is: " << this->scores_2 << std::endl;
    } else {
        std::cout << player1->name << " wins the whole game!" << std::endl;
        std::cout << player1->name << "'s score is: " << this->scores_1 << std::endl;
        std::cout << player2->name << "'s score is: " << this->scores_2 << std::endl;
    }
}
