#include "Scissors.h"

std::string Scissors::getName() {
    return "Scissors";
}

std::vector<std::string> Scissors::strongerThan() {
    return {"Paper"};
}