#include "Computer.h"

Computer::Computer() : Player("Computer") {}
Computer::Computer(std::string name): Player(name) {};
Move * Computer::makeMove() {
    Move* move = new Rock();
    return move;
}

std::string Computer::getName() {
    return "Computer";
}