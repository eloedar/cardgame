#include "player.h"

void Player::draw() {
    if (!this->deck.empty()) {
        this->hand.emplace_back(this->deck.back());
        this->deck.pop_back();
    }
}

/**
 * Please to remember to call card->effect after!
 * **/
Card &Player::play(int index) {
    Card &play = *(this->hand[index]);
//    this->hand.erase(this->hand.begin()+index);
    return play;
}

void Player::displayHand() {
    using namespace std;
    for (auto &i: this->hand) {
        cout << *i << endl;
    }
}

void Player::displayIndexedHand() {
    using namespace std;
    for (int i = 0; i < this->hand.size(); i++) {
        cout << i << ": " << *(this->hand[i]) << endl;
    }
}