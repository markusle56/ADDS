#ifndef PREFIXMATCHER_H
#define PREFIXMATCHER_H 
#include <vector> 
#include <string> 

using namespace std; 

struct TrieNode {
    bool isEndOfRouter;
    int routerNumber;
    vector<TrieNode*> children;
    TrieNode() : children(2, nullptr), isEndOfRouter(false), routerNumber(-1) {}
};

class PrefixMatcher {
    private:
        TrieNode * root;
    public:
    PrefixMatcher();
    int selectRouter(string networkAddress);  
    void insert(string address, int routerNumber);
};
#endif 