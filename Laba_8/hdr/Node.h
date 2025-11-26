#ifndef NODE_H
#define NODE_H

// Узел двухсвязного списка
template<typename T>
class Node {
public:
    T data;
    Node* next;
    Node* prev;

    Node(const T& value);
};

// Включение реализации шаблонов
#include <string>
#include "../src/Node.cpp"

#endif // NODE_H

