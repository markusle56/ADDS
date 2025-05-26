#include "Document.h"


Document::Document(string name, int license_limit): name(name), license_limit(license_limit) {}
string Document::getName() {
    return name;
}
int Document::getLicneseLimit() {
    return license_limit;
}
bool Document::borrowDocument() {
    if (license_limit <= 0) {
        return false; 
    } else {
        license_limit--;
        return true;
    }
}
void Document::returnDocument() {
    license_limit++;
    return;
}