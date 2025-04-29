#include "LinkedList.h"

LinkedList::LinkedList() {
    head = nullptr;
}
LinkedList::LinkedList(int* array, int len) {
    head = nullptr; 
    for (int i = 0; i < len; i++) {
        insertPosition(i,array[i]);
    }
}
LinkedList::~LinkedList() {
    Node * current = head; 
    while (current->next() != nullptr) {
        Node * next = current->next();
        delete current;
        current = next;
    }
}
void LinkedList::insertPosition(int pos, int newNum) {
    Node * newNode = new Node(newNum);
    if (pos == 0) {
        newNode->setNext(head);
        head = newNode;
        return;
    }
    Node * current = head;
    if (current == nullptr) {
        head = newNode;
        return;
    }
    for (int i = 1; i < pos - 1; i++) {
        if (current->next() == nullptr) {
            current->setNext(newNode);
            return;
        }
        current = current->next();
    }
    Node * nextpos = current->next();
    current->setNext(newNode);
    newNode->setNext(nextpos);
    return;
}
bool LinkedList::deletePosition(int pos) {  
    Node * current = head; 
    if (pos == 1) { 
        head = current->next();
        delete current; 
        return true;
    }
    if (current == nullptr) {
        return false;
    }

    for (int i = 1; i < pos - 1; i++) {
        if (current->next() == nullptr) {
            return false;
        }
        current = current->next();
    }
    if (current->next() == nullptr) {
        return false;
    }
    Node * nextpos = current->next();
    current->setNext(nextpos->next());
    delete nextpos;
    return true; 
}
int LinkedList::get(int pos) {
    Node * current = head; 
    if (pos <= 1) {
        return head->getData();
    }
    if (head->next() == nullptr) {
        return std::numeric_limits < int >::max();
    }
    for (int i = 1; i < pos; i++) {
        if (current->next() == nullptr) {
            return std::numeric_limits < int >::max();
        }
        current = current->next();
    };
    return current->getData();
}
int LinkedList::search(int target) {
    Node * current = head; 
    int pos= 1; 
    while (current !=nullptr) { 
        if (current->getData() == target) { 
            return pos;
        }
        pos++;
        current = current->next();
    }
    return -1; 
}
void LinkedList::printList() {
    Node * current = head;
    std::cout<<"[";
    while (current != nullptr) {
        std::cout << current->getData() << " ";
        current = current->next();
    }
    std::cout << "]" << std::endl;
    return;
}