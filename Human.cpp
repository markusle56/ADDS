#include "Human.h"

Human::Human(): Human("Human") {}    
Human::Human(std::string name): Player(name) {};

Move* Human::makeMove() {
    std::vector<std::string> valid = {"Pirate", "Scissors", "Paper", "Rock", "Zombie", "Robot", "Ninja", "Monkey"};
    std::string moveName = "";

    // Keep asking until a valid move is entered
    while (std::find(valid.begin(), valid.end(), moveName) == valid.end()) {
        std::cout << "Enter Move: ";
        std::cin >> moveName;
    }

    Move* move = nullptr;

    // Create the appropriate move based on user input
    if (moveName == "Pirate") {
        move = new Pirate;
    } else if (moveName == "Scissors") {
        move = new Scissors;
    } else if (moveName == "Paper") {
        move = new Paper;
    } else if (moveName == "Rock") {
        move = new Rock;
    } else if (moveName == "Zombie") {
        move = new Zombie;
    } else if (moveName == "Robot") {
        move = new Robot;
    } else if (moveName == "Ninja") {
        move = new Ninja;
    } else if (moveName == "Monkey") {
        move = new Monkey;
    }

    return move;
}

std::string Human::getName() {
    return name;
}