#include "Human.h"

Human::Human(): Human("Human") {}    
Human::Human(string name): Player(name) {};

char Human::makeMove() {
    char move = 'O';
    while (move != 'R' && move != 'S' && move != 'P') {
        cout<<"Enter move: ";
        cin>>move;
    }
    return move;
}

string Human::getName() {
    return name;
}