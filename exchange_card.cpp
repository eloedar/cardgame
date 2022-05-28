#include "exchange_card.h"

void ExchangeCard::effect(Card &opponentCard, Player &player, Player &opponent) {
    std::cout << "Exchange!" << std::endl;
    int tmp = opponentCard.defense;
    opponentCard.defense = opponentCard.attack;
    opponentCard.attack = tmp;
}
