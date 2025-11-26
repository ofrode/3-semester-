#ifndef NODE_H
#define NODE_H

#include <string>

// Узел двухсвязного списка
template<typename T>
class Node {
public:
    T data;
    Node* next = nullptr;
    Node* prev = nullptr;

    explicit Node(const T& value);
};

// Включение реализации шаблонов
#include "../src/Node.cpp"

#endif // NODE_H

