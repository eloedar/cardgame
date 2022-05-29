//
// Created by jiaji on 2022/5/29.
//

#include <algorithm>
#include <random>
#include "Croupier.h"

Croupier::Croupier(Player &player1, Player &player2, int Card_num, int BigBossCard_num, int ExchangeCard_num) :
        player1(player1), player2(player2), bigBossCard(BigBossCard("BigBossCard", 100, 100)),
        card(Card("BasicCard", 400, 400)),
        exchangeCard(ExchangeCard("ExchangeCard", 200, 200)) {
    ArgumentSetter(BigBossCard_num, ExchangeCard_num, Card_num);
    DeckGenerator();
    DeckShuffle();
    player1.deck = deck1;
    player2.deck = deck2;
    for (int i = 0; i < 5; ++i) {
        player1.draw();
        player2.draw();
    }
}

void Croupier::DeckGenerator() {
    for (int i = 0; i < Card_num; i++) {
        auto *tmpCard = new Card(card);
        deck1.push_back(tmpCard);
    }
    for (int i = 0; i < BigBossCard_num; i++) {
        auto *tmpCard = new BigBossCard(bigBossCard);
        deck1.push_back(tmpCard);
    }
    for (int i = 0; i < ExchangeCard_num; i++) {
        auto * tmpCard = new ExchangeCard(exchangeCard);
        deck1.push_back(tmpCard);
    }
    for (int i = 0; i < Card_num; i++) {
        auto *tmpCard = new Card(card);
        deck2.push_back(tmpCard);
    }
    for (int i = 0; i < BigBossCard_num; i++) {
        auto *tmpCard = new BigBossCard(bigBossCard);
        deck2.push_back(tmpCard);
    }
    for (int i = 0; i < ExchangeCard_num; i++) {
        auto * tmpCard = new ExchangeCard(exchangeCard);
        deck2.push_back(tmpCard);
    }
}

void Croupier::DeckShuffle() {
    std::shuffle(deck1.begin(), deck1.end(), std::mt19937(std::random_device()()));
    std::shuffle(deck2.begin(), deck2.end(), std::mt19937(std::random_device()()));
}

void Croupier::ArgumentSetter(int bigBossCard_num, int exchangeCard_num, int card_num) {
    this->BigBossCard_num = bigBossCard_num;
    this->ExchangeCard_num = exchangeCard_num;
    this->Card_num = card_num;
}
