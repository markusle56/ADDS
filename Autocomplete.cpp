#include "Autocomplete.h"
#include <ctype.h>


Autocomplete::Autocomplete() : root(new TrieNode) {}

void travel(string partialWord, TrieNode *current,vector<string> &ans) {
    if (current->isEndOfWord) {
        ans.push_back(partialWord); 
    }
    for (int i = 0; i < current->children.size(); i++ ) {
        if (current->children[i]) {
            char c = i+ 'a';
            travel(partialWord+c, current->children[i], ans);
        }
    }
    return;
}
vector<string> Autocomplete::getSuggestions(string partialWord) {
    int n = partialWord.length();
    vector<string> ans;
    TrieNode * current = root; 
    for (int i = 0; i < n; i++) {
        if (isalpha(partialWord[i])) {
            int pos = tolower(partialWord[i]) - 'a';
            if (current->children[pos]) {
                current = current->children[pos];
            }
        } else {
            return ans; 
        }
    }
    travel(partialWord, current, ans);
    return ans;
}
void Autocomplete::insert(string word) {
    TrieNode * current = root;
    
    int n = word.length();
    for (int i = 0; i < n; i++) {
        if (isalpha(word[i])) {
            int n = tolower(word[i]) - 'a'; 
            if (!current->children[n]) {
                current->children[n] = new TrieNode();
            }
            current = current->children[n];
        }
    }
    current->isEndOfWord = true; 
    return; 
}