#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include "Node.h"

template <typename T>
class LinkedList {
private:
    Node<T>* head;
    size_t size;

public:
    LinkedList();
    ~LinkedList();

    void pushFront(const T& value);
    void popFront();
    void print() const;
    void clear();
    std::size_t getSize() const;
};

#endif