#include "../hdr/Algorithms.h"
#include <string>

template <typename T>
Iterator<T> Algorithms<T>::binarySearch(const DoublyLinkedList<T> &list, const T &value)
{
    if (list.empty())
    {
        return list.end();
    }

    size_t size = list.getSize();
    if (size == 0)
    {
        return list.end();
    }

    Iterator<T> first = list.begin();
    Iterator<T> last = list.begin();
    for (size_t i = 0; i < size - 1; ++i)
    {
        ++last;
    }

    if (*first == value)
        return first;
    if (*last == value)
        return last;
    if (*first > value || *last < value)
        return list.end();

    for (Iterator<T> it = list.begin(); it != list.end(); ++it)
    {
        if (*it == value)
        {
            return it;
        }
        if (*it > value)
        {
            return list.end();
        }
    }

    return list.end();
}

template <typename T>
Iterator<T> Algorithms<T>::partition([[maybe_unused]] DoublyLinkedList<T> &list, Iterator<T> low, Iterator<T> high, std::function<bool(const T &, const T &)> compare)
{
    T pivot = *high;
    Iterator<T> i = low;

    for (Iterator<T> j = low; j != high; ++j)
    {
        if (compare(*j, pivot) || *j == pivot)
        {
            T temp = *i;
            *i = *j;
            *j = temp;
            ++i;
        }
    }

    T temp = *i;
    *i = *high;
    *high = temp;

    return i;
}

template <typename T>
bool isBefore(Iterator<T> before, Iterator<T> after, Iterator<T> end)
{
    Iterator<T> check = before;
    while (check != end)
    {
        if (check == after)
        {
            return true;
        }
        ++check;
    }
    return false;
}

template <typename T>
void Algorithms<T>::quickSortHelper(DoublyLinkedList<T> &list, Iterator<T> low, Iterator<T> high, std::function<bool(const T &, const T &)> compare)
{
    if (low == list.end() || high == list.end())
    {
        return;
    }

    if (low == high)
    {
        return;
    }

    if (!isBefore(low, high, list.end()))
    {
        return;
    }

    Iterator<T> pivot = partition(list, low, high, compare);

    if (pivot != list.begin() && pivot != low)
    {
        Iterator<T> pivotPrev = pivot;
        --pivotPrev;
        if (pivotPrev != list.end() && isBefore(low, pivotPrev, list.end()))
        {
            quickSortHelper(list, low, pivotPrev, compare);
        }
    }

    Iterator<T> pivotNext = pivot;
    ++pivotNext;
    if (pivotNext != list.end() && isBefore(pivotNext, high, list.end()))
    {
        quickSortHelper(list, pivotNext, high, compare);
    }
}

template <typename T>
void Algorithms<T>::quickSort(DoublyLinkedList<T> &list)
{
    quickSort(list, [](const T &a, const T &b)
              { return a < b; });
}

template <typename T>
void Algorithms<T>::quickSort(DoublyLinkedList<T> &list, std::function<bool(const T &, const T &)> compare)
{
    if (list.empty() || list.getSize() == 1)
    {
        return;
    }

    Iterator<T> low = list.begin();
    Iterator<T> high = list.begin();

    while (high != list.end())
    {
        Iterator<T> next = high;
        ++next;
        if (next == list.end())
        {
            break;
        }
        ++high;
    }

    quickSortHelper(list, low, high, compare);
}

template class Algorithms<int>;
template class Algorithms<double>;
template class Algorithms<std::string>;