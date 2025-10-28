#ifndef NODE_H
#define NODE_H

template <typename T>
struct Node {
    T data;
    Node<T>* next = nullptr;

    explicit Node(const T& value) : data(value) {}
};

#endif