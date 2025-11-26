#ifndef NODE_H
#define NODE_H

#include <string>

template <typename T>
class Node
{
public:
    T data;
    Node *next;
    Node *prev;

    explicit Node(const T &value);
};

#endif