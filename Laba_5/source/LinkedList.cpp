#include "../header/LinkedList.h"

template <typename T>
LinkedList<T>::LinkedList() : head(nullptr), size(0) {}

template <typename T>
LinkedList<T>::~LinkedList() { clear(); }

template <typename T>
void LinkedList<T>::pushFront(const T &value)
{
    Node<T> *node = new Node<T>(value);
    node->next = head;
    head = node;
    ++size;
}

template <typename T>
void LinkedList<T>::popFront()
{
    if (!head)
        return;
    Node<T> *tmp = head;
    head = head->next;
    delete tmp;
    --size;
}

template <typename T>
void LinkedList<T>::print() const
{
    Node<T> *current = head;
    while (current)
    {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << "\n";
}

template <typename T>
void LinkedList<T>::clear()
{
    while (head)
        popFront();
}

template <typename T>
size_t LinkedList<T>::getSize() const { return size; }

template class LinkedList<int>;
template class LinkedList<double>;
template class LinkedList<std::string>;