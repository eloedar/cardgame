#ifndef CARDGAME_EXCHANGE_CARD_H
#define CARDGAME_EXCHANGE_CARD_H

#include "card.h"

class ExchangeCard : public Card {
public:
    ExchangeCard(std::string name, int attack, int defense) : Card(name, attack, defense) {};
    void effect(Card &opponentCard, Player &player, Player &opponent) override {
        std::cout<<"Exchange!"<<std::endl;
        int tmp = opponentCard.defense;
        opponentCard.defense = opponentCard.attack;
        opponentCard.attack = tmp;
    }
};


#endif //CARDGAME_EXCHANGE_CARD_H
