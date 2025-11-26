#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include "DoublyLinkedList.h"
#include <string>
#include <functional>

template <typename T>
class Algorithms
{
public:
    static Iterator<T> binarySearch(DoublyLinkedList<T> &list, const T &value);

    static void quickSort(DoublyLinkedList<T> &list);

    static void quickSort(DoublyLinkedList<T> &list, std::function<bool(const T &, const T &)> compare);

private:
    static Iterator<T> partition(DoublyLinkedList<T> &list, Iterator<T> low, Iterator<T> high, std::function<bool(const T &, const T &)> compare);
    static void quickSortHelper(DoublyLinkedList<T> &list, Iterator<T> low, Iterator<T> high, std::function<bool(const T &, const T &)> compare);
};

#endif