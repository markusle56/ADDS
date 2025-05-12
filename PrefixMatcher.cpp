#include "PrefixMatcher.h"

PrefixMatcher::PrefixMatcher() : root(new TrieNode) {}

int PrefixMatcher::selectRouter(string networkAddress) {
    int ans = -1; 
    TrieNode * current = root;
    if (current->isEndOfRouter) {
        ans = current->routerNumber;
    }
    for (auto c : networkAddress) {
        if (c == '1' || c == '0') {
            if (current->children[c-'0']) {
                current = current->children[c-'0'];
                if (current->isEndOfRouter) {
                    ans = current->routerNumber;
                }
            } else {
                return ans; 
            }
        } else {
            return -1;
        }
    }
    return ans;
}
void PrefixMatcher::insert(string address, int routerNumber) {
    TrieNode * current = root; 
    for (auto c : address) {
        if (c == '0' || c == '1') {
            if (!current->children[c-'0']) {
                current->children[c-'0'] = new TrieNode;
            }
            current = current->children[c - '0'];
        } else {
            return;
        }
    }
    current->isEndOfRouter = true; 
    current->routerNumber = routerNumber; 
    return;
}