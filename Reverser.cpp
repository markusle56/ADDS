#include "Reverser.h"
using namespace std;

int Reverser::reverseDigit(int value) {
    if (value >= 0) {
        return value;
    } else {
        int digit = value % 10; 
        
        int ex = value;
        while (ex > 0) {
            digit *=10;
            ex /=10;
        }
        value /=10;
        return digit+reverseDigit(value);
    }
}
string Reverser::reverseString(string characters) {
    if (characters.size() <= 1) {
        return characters; 
    } 
    string lastchar = characters.substr(characters.size()-1, 1);
    string subString = characters.substr(0, characters.size() - 1);
    return lastchar + reverseString(subString);
}