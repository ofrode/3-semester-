#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <cstddef>
#include <string>
#include "Node.h"

template<typename T>
class DoublyLinkedList;

// Итератор для двухсвязного списка
template<typename T>
class Iterator {
private:
    Node<T>* current;

public:
    explicit Iterator(Node<T>* node) : current(node) {}

    // Оператор разыменования
    T& operator*() {
        return current->data;
    }

    // Оператор доступа к члену
    T* operator->() {
        return &(current->data);
    }

    // Префиксный инкремент
    Iterator& operator++() {
        if (current) {
            current = current->next;
        }
        return *this;
    }

    // Постфиксный инкремент
    Iterator operator++(int) {
        Iterator temp = *this;
        ++(*this);
        return temp;
    }

    // Префиксный декремент
    Iterator& operator--() {
        if (current) {
            current = current->prev;
        }
        return *this;
    }

    // Постфиксный декремент
    Iterator operator--(int) {
        Iterator temp = *this;
        --(*this);
        return temp;
    }

    // Оператор сравнения
    bool operator==(const Iterator& other) = default;

    // Дружественный класс для доступа к current
    friend class DoublyLinkedList<T>;
};

// Класс контейнера двухсвязного списка
template<typename T>
class DoublyLinkedList {
private:
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;
    size_t size = 0;

public:
    // Конструктор
    DoublyLinkedList() = default;

    // Деструктор
    ~DoublyLinkedList() {
        clear();
    }

    // Копирующий конструктор
    DoublyLinkedList(const DoublyLinkedList& other) {
        Node<T>* current = other.head;
        while (current) {
            push_back(current->data);
            current = current->next;
        }
    }

    // Оператор присваивания
    DoublyLinkedList& operator=(const DoublyLinkedList& other) {
        if (this != &other) {
            clear();
            Node<T>* current = other.head;
            while (current) {
                push_back(current->data);
                current = current->next;
            }
        }
        return *this;
    }

    // Добавление элемента в конец
    void push_back(const T& value);

    // Добавление элемента в начало
    void push_front(const T& value);

    // Удаление элемента с конца
    void pop_back();

    // Удаление элемента с начала
    void pop_front();

    // Вставка элемента в позицию
    void insert(Iterator<T> pos, const T& value);

    // Удаление элемента в позиции
    void erase(Iterator<T> pos);

    // Очистка списка
    void clear();

    // Получение размера
    size_t getSize() const {
        return size;
    }

    // Проверка на пустоту
    bool empty() const {
        return size == 0;
    }

    // Получение итератора на начало
    Iterator<T> begin() const {
        return Iterator<T>(head);
    }

    // Получение итератора на конец
    Iterator<T> end() const {
        return Iterator<T>(nullptr);
    }

    // Получение первого элемента
    T& front() {
        return head->data;
    }

    // Получение последнего элемента
    T& back() {
        return tail->data;
    }
};

#endif // DOUBLYLINKEDLIST_H

