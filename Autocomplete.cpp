#include "Autocomplete.h"
#include <ctype.h>


Autocomplete::Autocomplete() : trie(new TrieNode) {}

void travel(string partialWord, TrieNode *start,vector<string> &ans) {
    if (start->isEndOfWord) {
        ans.push_back(partialWord); 
    }
    for (int i = 0; i < start->children.size(); i++ ) {
        if (start->children[i]) {
            char c = i+ 'a';
            travel(partialWord+c, start->children[i], ans);
        }
    }
    return;
}
vector<string> Autocomplete::getSuggestions(string partialWord) {
    int n = partialWord.length();
    vector<string> ans;
    TrieNode * start = trie; 
    for (int i = 0; i < n; i++) {
        if (isalpha(partialWord[i])) {
            int pos = tolower(partialWord[i]) - 'a';
            if (start->children[pos]) {
                start = start->children[pos];
            }
        } else {
            return ans; 
        }
    }
    travel(partialWord, start, ans);
    return ans;
}
void Autocomplete::insert(string word) {
    TrieNode * start = trie;
    
    int n = word.length();
    for (int i = 0; i < n; i++) {
        if (isalpha(word[i])) {
            int n = tolower(word[i]) - 'a'; 
            if (start->children[n]) {
                start = start->children[n];
            } else {
                start->children[n] = new TrieNode();
                start = start->children[n];
            }
        }
    }
    start->isEndOfWord = true; 
    return; 
}