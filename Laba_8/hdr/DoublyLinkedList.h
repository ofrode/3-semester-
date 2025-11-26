#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <cstddef>
#include <string>
#include "Node.h"

template <typename T>
class DoublyLinkedList;

template <typename T>
class Iterator
{
private:
    Node<T> *current;

public:
    explicit Iterator(Node<T> *node) : current(node) {}

    T &operator*()
    {
        return current->data;
    }

    T *operator->()
    {
        return &(current->data);
    }

    Iterator &operator++()
    {
        if (current)
        {
            current = current->next;
        }
        return *this;
    }

    Iterator operator++(int)
    {
        Iterator temp = *this;
        ++(*this);
        return temp;
    }

    Iterator &operator--()
    {
        if (current)
        {
            current = current->prev;
        }
        return *this;
    }

    Iterator operator--(int)
    {
        Iterator temp = *this;
        --(*this);
        return temp;
    }

    bool operator==(const Iterator &other) = default;

    friend class DoublyLinkedList<T>;
};

template <typename T>
class DoublyLinkedList
{
private:
    Node<T> *head = nullptr;
    Node<T> *tail = nullptr;
    size_t size = 0;

public:
    DoublyLinkedList() = default;

    ~DoublyLinkedList()
    {
        clear();
    }

    DoublyLinkedList(const DoublyLinkedList &other)
    {
        Node<T> *current = other.head;
        while (current)
        {
            push_back(current->data);
            current = current->next;
        }
    }

    DoublyLinkedList &operator=(const DoublyLinkedList &other)
    {
        if (this != &other)
        {
            clear();
            Node<T> *current = other.head;
            while (current)
            {
                push_back(current->data);
                current = current->next;
            }
        }
        return *this;
    }

    void push_back(const T &value);

    void push_front(const T &value);

    void pop_back();

    void pop_front();

    void insert(Iterator<T> pos, const T &value);

    void erase(Iterator<T> pos);

    void clear();

    size_t getSize() const
    {
        return size;
    }

    bool empty() const
    {
        return size == 0;
    }

    Iterator<T> begin() const
    {
        return Iterator<T>(head);
    }

    Iterator<T> end() const
    {
        return Iterator<T>(nullptr);
    }

    T &front()
    {
        return head->data;
    }

    T &back()
    {
        return tail->data;
    }
};

#endif