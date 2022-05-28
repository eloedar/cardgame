#ifndef CARDGAME_EXCHANGE_CARD_H
#define CARDGAME_EXCHANGE_CARD_H

#include "card.h"

#include <utility>

class ExchangeCard : public Card {
public:
    ExchangeCard(std::string name, int attack, int defense) : Card(std::move(name), attack, defense) {};
    void effect(Card &opponentCard, Player &player, Player &opponent) override;
};


#endif //CARDGAME_EXCHANGE_CARD_H
