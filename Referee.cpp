#include "Referee.h"

Referee::Referee() {}
Player * Referee::refGame(Player * player1, Player * player2) {
    Move* move1 = player1->makeMove();
    Move* move2 = player2->makeMove();
    std::vector<std::string> move1Stronger = move1->strongerThan();
    std::vector<std::string> move2Stronger = move2->strongerThan();
    if (std::find(move1Stronger.begin(),move1Stronger.end(), move2->getName()) != move1Stronger.end()) {
        return player1;
    }
    if (std::find(move2Stronger.begin(),move2Stronger.end(), move1->getName()) != move2Stronger.end()) {
        return player2;
    }
    return nullptr;
}
