#ifndef ZOMBIE_H
#define ZOMBIE_H

#include "Move.h"

class Zombie : public Move {
public:
    std::string getName() override;
    std::vector<std::string> strongerThan() override;
};

#endif