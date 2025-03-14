#include "Rock.h"

std::string Rock::getName() {
    return "Rock";
}
std::vector<std::string> Rock::strongerThan() {
    return {"Scissors"};
}