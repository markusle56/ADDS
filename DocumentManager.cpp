#include "DocumentManager.h"

DocumentManager::DocumentManager() {}

void DocumentManager::addDocument(string name, int id, int license_limit) {
    Document doc(name, license_limit);
    documents.emplace(id, doc);
    return;
}

void DocumentManager::addPatron(int patronID) {
    patron.insert(patronID);
}

int DocumentManager::search(string name) {
    for (auto doc : documents) {
        if (doc.second.getName() == name) {
            return doc.first;
        }
    }
    return 0;
}
bool DocumentManager::borrowDocument(int docid, int patronID) {
    if (documents.find(docid) != documents.end() && documents[docid].borrowDocument()) {
        return true;
    }
    return false;
}
void DocumentManager::returnDocument(int docid, int patronID) {
    if (documents.find(docid) != documents.end()) {
        documents[docid].returnDocument();
    }
    return;
}