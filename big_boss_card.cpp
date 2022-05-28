#include "big_boss_card.h"
#include "player.h"

void BigBossCard::effect(Card &opponentCard, Player &player, Player &opponent) {
    this->attack += opponentCard.attack;
    this->defense += opponentCard.defense;
    for (auto & i : player.hand) {
        i->attack += opponentCard.attack;
        i->defense += opponentCard.defense;
    }
    for (int i = 0; i < opponent.hand.size(); ++i) {
        if (opponent.hand[i]->attack == this->attack || opponent.hand[i]->defense == this->defense) {
            opponent.hand.erase(opponent.hand.begin() + i);
        }
    }
}
