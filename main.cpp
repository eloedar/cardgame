#include <iostream>
#include <vector>

#include "card.h"
#include "exchange_card.h"
#include "player.h"
#include "big_boss_card.h"
#include "game_control.h"

using namespace std;

int main() {
    Card card = Card("SuperSuperStringCard", 800, 800);
    Card card1 = Card("JustSoSoCard", 200, 300);
    ExchangeCard card2 = ExchangeCard("ExchangeCard", 100, 300);
    BigBossCard card3 = BigBossCard("BigBossCard", 100, 300);
    Card card4 = Card("VeryStrongCard", 200, 400);
    Card card5 = Card("SuperStrongCard", 300, 600);
    Card card6 = Card("AverageStrongCard", 400, 500);
    
    std::vector<Card*> deck = {&card, &card2, &card3, &card4, &card5, &card6, &card4, &card4, &card4};
    std::vector<Card*> opponentDeck = {&card4, &card4, &card, &card2, &card3, &card4, &card5};

    Player player = Player(deck, "John");
    Player opponent = Player(opponentDeck, "Alice");

    GameControl gameControl = GameControl(deck,opponentDeck,player,opponent);
    gameControl.start_game(5);
}