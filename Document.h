#ifndef DOCUMENT_H
#define DOCUMENT_H


#include <string>

using namespace std;

class Document {
    private:
        string name;
        int license_limit;
    public: 
        Document(string name, int license_limit);
        string getName();
        int getLicneseLimit();
        bool borrowDocument();
        void returnDocument();
};
#endif