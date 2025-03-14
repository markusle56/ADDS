#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include "Move.h"
#include "Rock.h"
#include "Scissors.h"
#include "Paper.h"
#include "Monkey.h"
#include "Pirate.h"
#include "Robot.h"
#include "Ninja.h"
#include "Zombie.h"


class Player {
    protected: 
        std::string name; 
        Move * move; 
    public: 
        Player(std::string name);
        Player();
        virtual Move * makeMove() = 0;
        virtual std::string getName() = 0;
        virtual ~Player() = default;
};
#endif   