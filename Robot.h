#ifndef ROBOT_H
#define ROBOT_H

#include "Move.h"

class Robot : public Move {
public:
    std::string getName() override;
    std::vector<std::string> strongerThan() override;
};

#endif