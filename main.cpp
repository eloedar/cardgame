#include <iostream>
#include <vector>

#include "card.h"
#include "exchange_card.h"
#include "player.h"
#include "big_boss_card.h"
#include "game_control.h"
#include "Croupier.h"

using namespace std;

int main() {
    std::vector<Card*> deck;
    std::vector<Card*> opponentDeck;

    Player player = Player(deck, "John");
    Player opponent = Player(opponentDeck, "Alice");

    Croupier croupier = Croupier(player, opponent,10,1,2);

    GameControl gameControl = GameControl(player.deck,opponent.deck,player,opponent);
    gameControl.start_game(2);
}