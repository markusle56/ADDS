#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include "Node.h"
#include <limits> 

class LinkedList {
    private: 
        Node *head;
    public:
        LinkedList();
        LinkedList(int* array, int len);
        ~LinkedList();
        void insertPosition(int pos, int newNum); 
        bool deletePosition(int pos);
        int get(int pos);
        int search(int target);
        void printList();

        void deleteHead() {
            if (!head) {
                return;
            }
            Node *todelete = head;
            head = head->next();
            delete todelete;
            return;
        }

        void deleteLast() {
            if(!head) {
                return;
            }
            Node *dummy = new Node(0);
            dummy->setNext(head);
            Node *current = dummy;
            while(current->next()->next()) {
                current = current->next();
            }
            Node *todelete = current->next();
            current->setNext(nullptr);
            head = dummy->next();
            delete todelete;
            delete dummy;
            
            return; 
        }

        void deletePos(int pos) {
            Node *dummy = new Node(0);
            dummy->setNext(head);
            Node *current = dummy;
            int count = 0;
            while(current->next() && count < pos) {
                count++;
                current = current->next();
            }
            if (current->next()) {
                Node* toDelete = current->next();
                current->setNext(toDelete->next());
                delete toDelete;;
            }
            head=dummy->next();
            delete dummy; 
            return;
        }

        void deleteVal(int val) {
            Node *dummy = new Node(0);
            dummy->setNext(head);
            Node *current = dummy;
            
            while(current->next() && current->next()->getData() != val) {
                current= current->next();
            }

            if (current->next()) {
                Node * toDelete = current->next();
                current->setNext(toDelete->next());
                delete toDelete;
            }
            head=dummy->next();
            delete dummy; 
            return;
        }
        Node * findPos(int i) {
            if (i < 0) {
                return nullptr;
            }
            Node * current = head;
            int count = 0;
            while(current && count <i) {
                current= current->next();
                count++;
            }
            return current;
        }
        void swapVal(int i, int j) {
            Node * pointi = findPos(i);
            Node * pointj = findPos(j);

            if (!pointi || !pointj) {
                return;
            }
            int tem = pointi->getData();
            pointi->setData(pointj->getData());
            pointj->setData(tem);
            return;
        }

        void swapNode(int i, int j) {
            Node *dummy = new Node(0);
            dummy->setNext(head);
            if (i > j) {
                int tem = i;
                i = j; 
                j = tem;
            }
            Node * prei;
            if (i == 0) {
                prei = dummy;
            } else {
                prei = findPos(i-1);
            }
            Node * prej = findPos(j-1);

            if (!prei || !prej || !prei->next() || !prej->next()) {
                delete dummy;
                return;
            }

            Node * pointi = prei->next();
            Node * pointj = prej->next();
            prei->setNext(pointj);
            prej->setNext(pointi);
            Node * buffer = pointi->next();
            pointi->setNext(pointj->next());
            pointj->setNext(buffer);
            head = dummy->next();
            delete dummy;
        }

        void rmdub() {
            Node * cur = head;
            while (cur && cur->next()) {
                if(cur->getData() == cur->next()->getData()) {
                    Node * todelete = cur->next();
                    cur->setNext(todelete->next()); 
                    delete todelete;
                } else {
                    cur = cur->next();
                }
            }
        }
        void deleteMiddle() { 
            Node * cur = head; 
            int n = 0; 
            while(cur) {
                n++;
                cur = cur->next();
            }
            int mid = n/2 + 1;
            Node * todelete = head; 
            n=1;
            while(cur && n < mid) {
                n++;
                cur = todelete;
                todelete = todelete->next();
            }
            cur->setNext(todelete->next());
            delete todelete;
            return;
        }

        void deleteformend(int th) {
            Node *dummy = new Node(0);
            dummy->setNext(head);
            Node *first, *second = dummy;
            first = first->next();
            for(int i = 0; i <th; i++) {
                if(first) {
                    first=first->next();
                } else {
                    return;
                }
            }
            while(first->next()) {
                first = first->next();
                second = second->next();
            }
            Node * todel = second->next();
            second->setNext(todel->next());
            delete todel;
            return; 
        }
};

#endif 