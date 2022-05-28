#include "card.h"

std::ostream &operator<<(std::ostream &os, const Card &card) {
    os << "name: " << card.name << ", "
       << "attack: " << card.attack << ", "
       << "defense: " << card.defense;
    return os;
}

void Card::effect(Card &opponentCard, Player &player, Player &opponent) {
    std::cout << "No effects!" << std::endl;
}

double Card::power(const Card &opponentCard) const {
    return (double) (this->attack - opponentCard.defense) / 2;
}