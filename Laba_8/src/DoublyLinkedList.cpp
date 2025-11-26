#include "../hdr/DoublyLinkedList.h"
#include <string>

// Реализация методов для DoublyLinkedList

template<typename T>
void DoublyLinkedList<T>::push_back(const T& value) {
    Node<T>* newNode = new Node<T>(value);
    
    if (tail == nullptr) {
        // Список пуст
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    size++;
}

template<typename T>
void DoublyLinkedList<T>::push_front(const T& value) {
    Node<T>* newNode = new Node<T>(value);
    
    if (head == nullptr) {
        // Список пуст
        head = tail = newNode;
    } else {
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }
    size++;
}

template<typename T>
void DoublyLinkedList<T>::pop_back() {
    if (tail == nullptr) {
        return;
    }
    
    Node<T>* temp = tail;
    if (tail == head) {
        // Один элемент
        head = tail = nullptr;
    } else {
        tail = tail->prev;
        tail->next = nullptr;
    }
    delete temp;
    size--;
}

template<typename T>
void DoublyLinkedList<T>::pop_front() {
    if (head == nullptr) {
        return;
    }
    
    Node<T>* temp = head;
    if (head == tail) {
        // Один элемент
        head = tail = nullptr;
    } else {
        head = head->next;
        head->prev = nullptr;
    }
    delete temp;
    size--;
}

template<typename T>
void DoublyLinkedList<T>::insert(Iterator<T> pos, const T& value) {
    if (pos.current == nullptr) {
        // Вставка в конец
        push_back(value);
        return;
    }
    
    if (pos.current == head) {
        // Вставка в начало
        push_front(value);
        return;
    }
    
    Node<T>* newNode = new Node<T>(value);
    newNode->next = pos.current;
    newNode->prev = pos.current->prev;
    pos.current->prev->next = newNode;
    pos.current->prev = newNode;
    size++;
}

template<typename T>
void DoublyLinkedList<T>::erase(Iterator<T> pos) {
    if (pos.current == nullptr) {
        return;
    }
    
    if (pos.current == head) {
        pop_front();
        return;
    }
    
    if (pos.current == tail) {
        pop_back();
        return;
    }
    
    pos.current->prev->next = pos.current->next;
    pos.current->next->prev = pos.current->prev;
    delete pos.current;
    size--;
}

template<typename T>
void DoublyLinkedList<T>::clear() {
    while (head != nullptr) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
    size = 0;
}

// Явное инстанцирование для часто используемых типов
template class DoublyLinkedList<int>;
template class DoublyLinkedList<double>;
template class DoublyLinkedList<std::string>;

