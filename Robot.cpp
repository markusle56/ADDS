#include "Robot.h"

std::string Robot::getName() {
    return "Robot";
}

std::vector<std::string> Robot::strongerThan() {
    return {"Zombie", "Ninja"};
}