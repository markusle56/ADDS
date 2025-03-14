#ifndef HUMAN_H
#define HUMAN_H
#include "Player.h"

class Human : public Player {
    public: 
        Human(); 
        Human(std::string name);  
        std::string getName() override;
        Move * makeMove() override;

};
#endif