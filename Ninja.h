#ifndef NINJA_H
#define NINJA_H

#include "Move.h"

class Ninja : public Move {
public:
    std::string getName() override;
    std::vector<std::string> strongerThan() override;
};
#endif