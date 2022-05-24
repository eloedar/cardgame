#include <iostream>
#include <vector>

#include "card.h"
#include "exchange_card.h"
#include "player.h"
#include "big_boss_card.h"
#include "game_control.h"

using namespace std;

int main() {
    Card card = ExchangeCard("card", 100, 200);
    ExchangeCard card2 = ExchangeCard("exchange card", 100, 300);
    BigBossCard card3 = BigBossCard("name3", 100, 300);
    Card card4 = Card("name4", 200, 400);
    Card card5 = Card("name5", 300, 600);
    Card card6 = Card("name6", 400, 500);
    
    std::vector<Card*> deck = {&card, &card2, &card3, &card4, &card5, &card6, &card4, &card4, &card4};
    std::vector<Card*> opponentDeck = {&card4, &card4, &card, &card2, &card3, &card4, &card5};

    Player player = Player(deck, "John");
    Player opponent = Player(opponentDeck, "Alice");

    GameControl gameControl = GameControl(deck,opponentDeck,player,opponent);
    gameControl.start_game(5);
}