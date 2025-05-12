#ifndef AUTOCOMPLETE_H
#define AUTOCOMPLETE_H
#include <vector> 
#include <string> 

using namespace std; 
struct TrieNode {
    bool isEndOfWord;
    vector<TrieNode*> children;
    TrieNode() : children(26, nullptr), isEndOfWord(false) {}
};

class Autocomplete {
    private:
        TrieNode * root; 
    public: 
        Autocomplete();
        vector<string> getSuggestions(string partialWord);  // return the known words that start with partialWord

        void insert(string word); // add a word to the known words
};
#endif 