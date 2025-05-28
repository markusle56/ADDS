#include "DocumentManager.h"

DocumentManager::DocumentManager() {}

void DocumentManager::addDocument(string name, int id, int license_limit) {
    Document doc(name, license_limit);
    documents.insert({id, doc});
    return;
}

void DocumentManager::addPatron(int patronID) {
    patron.insert(patronID);
}

int DocumentManager::search(string name) {
    for (auto doc : documents) {
        if (doc.second.name == name) {
            return doc.first;
        }
    }
    return 0;
}
bool DocumentManager::borrowDocument(int docid, int patronID) {
    auto it = documents.find(docid);
    if (it != documents.end()) {
        if (it->second.borrowDocument()) {
            return true;
        }
    }
    return false;
}
void DocumentManager::returnDocument(int docid, int patronID) {
    auto it = documents.find(docid);
    if (it != documents.end()) {
        it->second.returnDocument();
    }
    return;
}