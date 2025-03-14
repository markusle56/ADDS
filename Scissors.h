#ifndef SCISSORS_H
#define SCISSORS_H

#include "Move.h"

class Scissors : public Move {
public:
    std::string getName() override;
    std::vector<std::string> strongerThan() override;
};

#endif