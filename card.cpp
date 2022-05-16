#include "card.h"

std::ostream &operator<<(std::ostream &os, const Card &card) {
    os << "name: " << card.name << ", "
    << "attack: " << card.attack << ", "
    << "defense: " << card.defense;
    return os;
}
