#include <string>
#include <iostream>
#include "List.h"

using namespace std;


int main() {
    int hi;

    cin >> hi;

    List* list = new List();
    list->test();
    Node* node = new Node;
    node->value = 6;


    //*HERE = 5;


    Node* hello = new Node;
    cout << &hello << endl;


    Node* x = new Node;

    x->value = 5;
    cout << "{{" << x->value << "}}";
    delete x;
    Node* y = new Node;

    cout << "{{" << y->value << "}}";
    cout << x->value;
    list->insert_last(node);


    list->print();

    Node* loop = new Node;
    for(int i = 0; i < 15 ; i++) {
        loop->value = i;
        list->insert_last(loop);

        loop = new Node;
    }

    list->print();

    if(list->First() == nullptr || list->Last() == nullptr) {
        cout << "You fucked up somewhere" << endl;
        return 1;
    }

    cout << "Testing remove" << endl;
    int j = list->get_size();


    for(int i = j; i > j - 5; i--) {
        list->remove_loc(i-1);
        list->print();
    }

    cout << "Testing removing a certain loc" << endl;

    list->remove_loc(1);

    list->print();

    delete list;


    cout << "testing list" << endl;
    list->test();
    list->print();
    return 0;
}