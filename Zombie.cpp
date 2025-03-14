#include "Zombie.h"

std::string Zombie::getName() {
    return "Zombie";
}

std::vector<std::string> Zombie::strongerThan() {
    return {"Pirate", "Monkey"};
}