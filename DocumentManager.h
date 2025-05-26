#ifndef DOCUMENTMANAGER_H
#define DOCUMENTMANAGER_H

#include <string>
#include <unordered_set>
#include <unordered_map>
#include "Document.h"

/*
Because we need to store millions of data of documents and patrons, 
I use unordered_set and unordered_map to store data to reduce the
average time of addPatron(), borrowDocument(), returnDocument() to O(1).
However, the trade-off is that the function search() will have O(n) time
complexity. 
*/ 

using namespace std;

class DocumentManager {
    private: 
        unordered_set<int> patron;
        unordered_map<int, Document> documents;
    public:
        DocumentManager();

        void addDocument(string name, int id, int license_limit);

        void addPatron(int patronID);

        int search(string name); // returns docid if name is in the document collection or 0 if the name is not in the collection

        bool borrowDocument(int docid, int patronID);  // returns true if document is borrowed, false if it can not be borrowed (invalid patronid or the number of copies current borrowed has reached the license limit)

        void returnDocument(int docid, int patronID);
};
#endif