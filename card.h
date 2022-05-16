#pragma once

#include <iostream>

// for compilation
// https://stackoverflow.com/questions/4964482/how-to-create-two-classes-in-c-which-use-each-other-as-data
class Player;

/**
 * @brief Card Class
 *
 */
class Card {
public:
    /**
     * @brief name of card
     *
     */
    std::string name;

    /**
     * @brief attack of card
     *
     */
    int attack;

    /**
     * @brief defense of card
     *
     */
    int defense;

    Card(std::string name, int attack, int defense) : name(name), attack(attack), defense(defense) {};

    /**
     * @brief power equals to attack - oppenent card's
     * defense / 2, and will not get a minus value
     *
     * @param opponentCard opponent card
     * @return double power
     *
     * Card1: card1 100 200
     * Card2: card2 100 50
     *
     * Card1.power(Card2) => 75
     * Card2.power(Card1) => 0
     */
    double power(const Card &opponentCard) {
        return (double) (this->attack - opponentCard.defense) / 2;
    }

    /**
     * @brief different card has different effect.
     * A card has no effect by default
     *
     * @param opponentCard
     * @param player
     * @param opponent
     */
    virtual void effect(Card &opponentCard, Player &player, Player &opponent) {
        std::cout << "No effects!" << std::endl;
    };

    /**
     * @brief format card output
     * 
     * format: <name> <attack> <defense>
     *
     * @param os std::ostream
     * @param card card
     * @return std::ostream&
     *
     * example:
     *
     * name 100 200
     */
    friend std::ostream &operator<<(std::ostream &os, const Card &card);
};