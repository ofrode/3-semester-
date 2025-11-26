#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include "DoublyLinkedList.h"
#include <functional>

// Класс алгоритма для работы со списком
template<typename T>
class Algorithms {
public:
    // Бинарный поиск (требует отсортированный список)
    // Возвращает итератор на найденный элемент или end() если не найден
    static Iterator<T> binarySearch(DoublyLinkedList<T>& list, const T& value);
    
    // Быстрая сортировка
    static void quickSort(DoublyLinkedList<T>& list);
    
    // Быстрая сортировка с пользовательской функцией сравнения
    static void quickSort(DoublyLinkedList<T>& list, std::function<bool(const T&, const T&)> compare);

private:
    // Вспомогательные методы для быстрой сортировки
    static Iterator<T> partition(DoublyLinkedList<T>& list, Iterator<T> low, Iterator<T> high, std::function<bool(const T&, const T&)> compare);
    static void quickSortHelper(DoublyLinkedList<T>& list, Iterator<T> low, Iterator<T> high, std::function<bool(const T&, const T&)> compare);
};

// Включение реализации шаблонов
#include <string>
#include "../src/Algorithms.cpp"

#endif // ALGORITHMS_H

