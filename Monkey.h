#ifndef MONKEY_H
#define MONKEY_H

#include "Move.h"

class Monkey : public Move {
public:
    std::string getName() override;
    std::vector<std::string> strongerThan() override;
};

#endif