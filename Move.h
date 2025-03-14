#ifndef MOVE_H
#define MOVE_H
#include <iostream>
#include <string>
#include <vector>
class Move {
    public: 
        virtual std::string getName() = 0;
        virtual std::vector<std::string> strongerThan() = 0;
        virtual ~Move() = default;
};
#endif