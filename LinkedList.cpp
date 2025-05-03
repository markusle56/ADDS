#include "LinkedList.h"

LinkedList::LinkedList() {
    head = nullptr;
}
LinkedList::LinkedList(int* array, int len) {
    head = nullptr; 
    for (int i = 0; i < len; i++) {
        insertPosition(i+1,array[i]);
    }
}
LinkedList::~LinkedList() {
    Node * current = head; 
    while (current) {
        Node * next = current->next();
        delete current;
        current = next;
    }
}
void LinkedList::insertPosition(int pos, int newNum) {
    Node * newNode = new Node(newNum);
    if (!head || pos <=1) {
        newNode->setNext(head);
        head = newNode;
        return;
    }
    Node * current = head;
    int index = 1;
    while (current->next() && index < pos - 1) {
        current = current->next();
        index++;
    }
    newNode->setNext(current->next());
    current->setNext(newNode);
    return;
}
bool LinkedList::deletePosition(int pos) {  
    if (!head || pos < 1) {
        return false;
    }
    if (pos == 1) {
        Node* toDelete = head;
        head = head->next();
        delete toDelete;
        return true;
    }
    Node* current = head;
    int index = 1;
    while (current->next() && index < pos - 1) {
        current = current->next();
        index++;
    }
    Node* target = current->next();
    if (!target) return false;
    current->setNext(target->next());
    delete target;
    return true;
}
int LinkedList::get(int pos) {
    if (!head || pos < 1) {
        return std::numeric_limits<int>::max();
    }
    Node* current = head;
    int index = 1;
    while (current && index < pos) {
        current = current->next();
        ++index;
    }
    if (!current) {
        return std::numeric_limits<int>::max();
    }
    return current->getData();
}
int LinkedList::search(int target) {
    Node * current = head; 
    int pos= 1; 
    while (current) { 
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
    if (current == nullptr) {
        return;
    }
    std::cout<<"[";
    std::cout << current->getData();
    current = current->next();
    while (current) {
        std::cout<<" ";
        std::cout << current->getData();
        current = current->next();
    }
    std::cout << "]" << std::endl;
    return;
}