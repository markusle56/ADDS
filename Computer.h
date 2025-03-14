#ifndef COMPUTER_H 
#define COMPUTER_H 
#include "Player.h"

class Computer : public Player {
    public: 
        Computer();
        Computer(std::string name);
        Move * makeMove() override;
        std::string getName() override;
};
#endif 