#ifndef HUMAN_H
#define HUMAN_H
#include "Player.h"
class Human : public Player {
    public: 
        Human(); 
        Human(string name);  
        char makeMove();
        string getName();

};
#endif