#include "Autocomplete.h"
#include <ctype.h>

void travel(string partialWord, TrieNode *start,vector<string> &ans) {
    if (start->isEndOfWord) {
        ans.push_back(partialWord); 
    }
    int n = start->children.size();
    for (int i = 0; i <= n; i++ ) {
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
    TrieNode * start = nullptr; 
    for (int i = 0; i < n; i++) {
        if (isalpha(partialWord[i])) {
            int pos = tolower(partialWord[i]) - 'a';
            if (trie->children[pos]) {
                start = trie->children[pos];
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
        if (start->children.size() != 26) {
            start->children.resize(26);
        }
        if (isalpha(word[i])) {
            int n = tolower(word[i]) - 'a'; 
            if (start->children[n]) {
                start = start->children[n];
            } else {
                start->children[n] = new TrieNode();
                start = start->children[n];
                start->isEndOfWord = false;
            }
        }
    }
    start->isEndOfWord = true; 
    return; 
}