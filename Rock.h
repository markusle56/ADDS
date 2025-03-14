#ifndef ROCK_H
#define ROCK_H

#include "Move.h"

class Rock : public Move {
public:
    std::string getName() override;
    std::vector<std::string> strongerThan() override;
};

#endif 