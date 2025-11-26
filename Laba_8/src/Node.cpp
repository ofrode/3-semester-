#include "../hdr/Node.h"
#include <string>

// Реализация конструктора Node
template<typename T>
Node<T>::Node(const T& value) : data(value), next(nullptr), prev(nullptr) {}

// Явное инстанцирование для часто используемых типов
template class Node<int>;
template class Node<double>;
template class Node<std::string>;

