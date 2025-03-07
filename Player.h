#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <iostream>

using namespace std; 

class Player {
    protected: 
        string name; 
    public: 
        Player(string name);
        Player();
        virtual char makeMove() = 0;
        virtual string getName() = 0;
};
#endif   