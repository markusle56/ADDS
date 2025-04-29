#ifndef NODE_H
#define NODE_H
#include <iostream>

class Node { 
    private: 
        int data; 
        Node* link;
    public:
        Node(int data);
        Node * next();
        int getData();
        void setNext(Node * next);
};
 #endif