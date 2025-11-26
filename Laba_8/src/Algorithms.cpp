#include "../hdr/Algorithms.h"
#include <string>

// Бинарный поиск (для отсортированного списка)
// Примечание: бинарный поиск на связном списке неэффективен из-за отсутствия произвольного доступа
// Реализована упрощенная версия для демонстрации
template<typename T>
Iterator<T> Algorithms<T>::binarySearch(DoublyLinkedList<T>& list, const T& value) {
    if (list.empty()) {
        return list.end();
    }
    
    // Для связного списка используем упрощенный подход:
    // находим размер, затем используем линейный поиск с ранним выходом
    // (так как список отсортирован)
    
    size_t size = list.getSize();
    if (size == 0) {
        return list.end();
    }
    
    // Проверяем первый и последний элементы
    Iterator<T> first = list.begin();
    Iterator<T> last = list.begin();
    for (size_t i = 0; i < size - 1; ++i) {
        ++last;
    }
    
    if (*first == value) return first;
    if (*last == value) return last;
    if (*first > value || *last < value) return list.end();
    
    // Используем линейный поиск с ранним выходом (так как список отсортирован)
    // Это эффективнее, чем настоящий бинарный поиск на связном списке
    for (Iterator<T> it = list.begin(); it != list.end(); ++it) {
        if (*it == value) {
            return it;
        }
        if (*it > value) {
            // Список отсортирован, дальше искать не нужно
            return list.end();
        }
    }
    
    return list.end();
}

// Вспомогательная функция для быстрой сортировки - разделение
template<typename T>
Iterator<T> Algorithms<T>::partition([[maybe_unused]] DoublyLinkedList<T>& list, Iterator<T> low, Iterator<T> high, std::function<bool(const T&, const T&)> compare) {
    T pivot = *high;
    Iterator<T> i = low;
    
    // Находим позицию, где должен быть pivot
    for (Iterator<T> j = low; j != high; ++j) {
        if (compare(*j, pivot) || *j == pivot) {
            // Меняем местами *i и *j
            T temp = *i;
            *i = *j;
            *j = temp;
            ++i;
        }
    }
    
    // Меняем местами pivot и элемент в позиции i
    T temp = *i;
    *i = *high;
    *high = temp;
    
    return i;
}

// Вспомогательная функция для проверки, находится ли итератор before перед итератором after
template<typename T>
bool isBefore(Iterator<T> before, Iterator<T> after, Iterator<T> end) {
    Iterator<T> check = before;
    while (check != end) {
        if (check == after) {
            return true;
        }
        ++check;
    }
    return false;
}

// Вспомогательная функция для быстрой сортировки
template<typename T>
void Algorithms<T>::quickSortHelper(DoublyLinkedList<T>& list, Iterator<T> low, Iterator<T> high, std::function<bool(const T&, const T&)> compare) {
    if (low == list.end() || high == list.end()) {
        return;
    }
    
    if (low == high) {
        return;
    }
    
    // Проверяем, что low находится перед high
    if (!isBefore(low, high, list.end())) {
        return;
    }
    
    Iterator<T> pivot = partition(list, low, high, compare);
    
    // Сортировка левой части (элементы до pivot)
    if (pivot != list.begin() && pivot != low) {
        Iterator<T> pivotPrev = pivot;
        --pivotPrev;
        if (pivotPrev != list.end() && isBefore(low, pivotPrev, list.end())) {
            quickSortHelper(list, low, pivotPrev, compare);
        }
    }
    
    // Сортировка правой части (элементы после pivot)
    Iterator<T> pivotNext = pivot;
    ++pivotNext;
    if (pivotNext != list.end() && isBefore(pivotNext, high, list.end())) {
        quickSortHelper(list, pivotNext, high, compare);
    }
}

// Быстрая сортировка
template<typename T>
void Algorithms<T>::quickSort(DoublyLinkedList<T>& list) {
    quickSort(list, [](const T& a, const T& b) { return a < b; });
}

template<typename T>
void Algorithms<T>::quickSort(DoublyLinkedList<T>& list, std::function<bool(const T&, const T&)> compare) {
    if (list.empty() || list.getSize() == 1) {
        return;
    }
    
    Iterator<T> low = list.begin();
    Iterator<T> high = list.begin();
    
    // Находим последний элемент
    while (high != list.end()) {
        Iterator<T> next = high;
        ++next;
        if (next == list.end()) {
            break;
        }
        ++high;
    }
    
    quickSortHelper(list, low, high, compare);
}

// Явное инстанцирование для часто используемых типов
template class Algorithms<int>;
template class Algorithms<double>;
template class Algorithms<std::string>;

