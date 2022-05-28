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

    Card card_oppo = Card("SuperSuperStringCard", 800, 800);
    Card card_oppo1 = Card("JustSoSoCard", 200, 300);
    ExchangeCard card_oppo2 = ExchangeCard("ExchangeCard", 100, 300);
    BigBossCard card_oppo3 = BigBossCard("BigBossCard", 100, 300);
    Card card_oppo4 = Card("VeryStrongCard", 200, 400);
    Card card_oppo5 = Card("SuperStrongCard", 300, 600);
    Card card_oppo6 = Card("AverageStrongCard", 400, 500);
    
    std::vector<Card*> deck = {&card, &card2, &card3, &card4, &card5, &card6, &card4, &card3, &card2};
    std::vector<Card*> opponentDeck = {&card_oppo4, &card_oppo4, &card_oppo, &card_oppo2, &card_oppo3, &card_oppo4, &card_oppo5};

    Player player = Player(deck, "John");
    Player opponent = Player(opponentDeck, "Alice");

    GameControl gameControl = GameControl(deck,opponentDeck,player,opponent);
    gameControl.start_game(2);
}