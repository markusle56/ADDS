#include "Paper.h"

std::string Paper::getName() {
    return "Paper";
}
std::vector<std::string> Paper::strongerThan() {
    return {"Rock"};
}