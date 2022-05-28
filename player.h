#pragma once

#include <iostream>
#include <utility>
#include <vector>

#include "card.h"

class Player {
public:
    /**
     * @brief deck of player
     * 
     */
    std::vector<Card*> deck;

    /**
     * @brief name of player
     * 
     */
    std::string name;

    /**
     * @brief cards in player's hand
     * players draw card from deck to hand
     * 
     */
    std::vector<Card*> hand;

    Player(std::vector<Card*> &deck, std::string name) : name(std::move(name)), deck(deck) {
        this->hand = std::vector<Card*>();
        for (int i = 0; i < 5; ++i) {
            this->draw();
        }
    };

    /**
     * @brief draw card from top of the deck
     * 
     * we consider back of the vector is the top of the deck  
     */
    void draw();

    /**
     * @brief play card in hand of the given index
     * and remove it from hand
     * 
     * we make sure that index is in range
     * 
     * @param index index of card
     * @return Card the card
     */
    Card & play(int index);

    /**
     * @brief display all cards in hand, every card is displayed
     * in one line
     * 
     * example:
     * 
     * card1 10 10
     * card2 20 20
     * card3 20 20
     */
    void displayHand();

    void displayIndexedHand();
};