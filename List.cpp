//
// Created by Chris Bartha on 12/10/19.
//

#include "List.h"

bool List::insert_last(Node* node) {
    if(size==0) {
        first = node;
        last = node;

        size++;
    } else if(size==1) {
        last = node;
        first->next = node;
        node->prev = first;

        size++;
    } else {
        last->next = node;
        node->prev = last;
        last = node;

        size++;
    }

    return true;
}

int List::get_size() {
    return size;
}

void List::print() {
    if (size == 0) return;
    cout << "{ ";
    Node* curr = new Node;
    curr = first;

    do {
        cout << curr->value << " ";
        curr = curr->next;
    } while (curr != nullptr);

    cout << "} (" << size << ")" << endl;

    delete curr;
}

bool List::remove_loc(int loc) {
    assert(size);

    if(loc > size || loc <= 0) assert(0);
    if(loc == size) {
        Node* node;
        node = last->prev;
        delete last;
        last = node;
        last->next = nullptr;
        size--;
        return true;
    } else if(loc == 1) {
        Node* node;
        node = first->next;
        delete first;
        first = node;
        first->prev = nullptr;
        size--;
        return true;
    }

    Node* curr;
    curr = first;
    int counter = 1;

    while(counter != loc) {
        curr = curr->next;
        counter++;
    }

    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;

    delete curr;
    size--;
    return true;
}

void List::test() {
    if(size != 0 && (first == nullptr || last == nullptr)) {
        cout << "You fucked up somewhere" << endl;
    }

    if(size != 0 && (first->prev != nullptr)) {
        cout << "first has a prev" << endl;
    }

    if(size != 0 && (last->next != nullptr)) {
        cout << "last has a next" << endl;
    }

    if(size == 0 && ((last != nullptr || first != nullptr))) {
        cout << "something is reeeaaaalllyyyy fucked up" << endl;
    }

    if(size != 0 && (last->next != nullptr && first->prev!=nullptr)) {
        cout << "I dont understand" << endl;
    }
}

List::~List() {
    assert(size);
    cout << "first val " << first->value << endl;
    cout << "last val  " << last->value << endl;
    Node* node = new Node;
    Node* temp = new Node;

    int j = size;

    for(int i = j; i <= 0; i--) {
        remove_loc(i);
    }


    cout << "first val " << first->value << endl;
    cout << "last val  " << last->value << endl;

    size = 0;
}

List::List() = default;







