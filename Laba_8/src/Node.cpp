#include "../hdr/Node.h"
#include <string>

template <typename T>
Node<T>::Node(const T &value) : data(value) {}

template class Node<int>;
template class Node<double>;
template class Node<std::string>;