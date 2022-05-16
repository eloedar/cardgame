#include "player.h"

void Player::draw() {
    this->hand.emplace_back(this->deck.back());
    this->deck.pop_back();
}
/**
 * Please to remember to call card->effect after!
 * **/
Card Player::play(int index) {
    Card& play = this->hand[index];
    this->hand.erase(this->hand.begin()+index);
    return play;
}

void Player::displayHand() {
    using namespace std;
    for (auto & i : this->hand) {
        cout << i << endl;
    }
}