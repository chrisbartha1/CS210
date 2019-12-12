#include <string>
#include <iostream>

using namespace std;
//
// Created by Chris Bartha on 12/10/19.
//
struct Node {
    Node* prev;
    Node* next;
    int value;
};


class List {
    private:
        Node* first = new Node;
        Node* last = new Node;
        int size=0;

    public:
        List();
        ~List();

        Node* First() {
            return first;
        }

        Node* Last() {
            return last;
        }

        /*bool insert_first();

        bool insert_pos(int pos);*/
        bool insert_last(Node* node);
        int get_size();
        void print();
        bool remove_loc(int loc);
        void test();


};

#ifndef UNTITLED1_LIST_H
#define UNTITLED1_LIST_H

#endif //UNTITLED1_LIST_H
