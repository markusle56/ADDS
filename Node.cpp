#include "Node.h"

Node::Node(int data): data(data), link(nullptr) {}
Node * Node::next() {
    return link;
}
int Node::getData() {
    return data;
}
void Node::setNext(Node * next) {
    link = next;
    return;
}

void Node::setData(int val) {
    data = val;
}