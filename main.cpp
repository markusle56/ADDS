#include "Player.h"
#include "Human.h"
#include "Computer.h"
#include "Referee.h"

int main() {
    Player * human = new Human();
    Player * computer = new Computer(); 
    Referee referee; 
    Player * winner = referee.refGame(human, computer);
    if (winner == nullptr) {
        cout<<"It's a Tie"<<endl;
    } else {
        cout<<winner->getName()<< " Wins"<<endl;
    }
    // delete human;
    // delete computer;
    return 0; 
}