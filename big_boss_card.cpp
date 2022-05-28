#include "big_boss_card.h"


void BigBossCard::effect(Card &opponentCard, Player &player, Player &opponent) {
    std::cout << "Big Boss!" << std::endl;
    this->attack += opponentCard.attack;
    this->defense += opponentCard.defense;
    for (auto & i : player.hand) {
        Card tmpCard = *i;
        tmpCard.attack += opponentCard.attack;
        tmpCard.defense += opponentCard.defense;
        i = new Card(tmpCard);
    }
    for (int i = 0; i < opponent.hand.size(); ++i) {
        if (opponent.hand[i]->attack == this->attack || opponent.hand[i]->defense == this->defense) {
            opponent.hand.erase(opponent.hand.begin() + i);
        }
    }
}
