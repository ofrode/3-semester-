#ifndef MENU_H
#define MENU_H

#include "DoublyLinkedList.h"
#include "Algorithms.h"
#include <iostream>

// Класс меню для работы со списком
class Menu {
public:
    // Запуск главного меню
    static void run();
    
private:
    // Печать списка
    static void printList(const DoublyLinkedList<int>& list);
    
    // Интерактивное меню
    static void showMenu();
    static void processChoice(DoublyLinkedList<int>& list, int choice);
    
    // Заполнение списка
    static void fillListManually(DoublyLinkedList<int>& list);
    static void fillListWithTestData(DoublyLinkedList<int>& list);
    
    // Сортировка списка
    static void sortList(DoublyLinkedList<int>& list);
    
    // Поиск в списке
    static void searchInList(const DoublyLinkedList<int>& list);
    
    // Удаление из списка
    static void deleteElement(DoublyLinkedList<int>& list);
    static void clearList(DoublyLinkedList<int>& list);
    
    // Вспомогательные функции для deleteElement
    static void deleteFirstElement(DoublyLinkedList<int>& list);
    static void deleteLastElement(DoublyLinkedList<int>& list);
    static void deleteByValue(DoublyLinkedList<int>& list);
    static void deleteByPosition(DoublyLinkedList<int>& list);
    
    // Демонстрация операций со списком
    static void demonstrateListOperations();
    
    // Демонстрация итератора
    static void demonstrateIterator();
    
    // Демонстрация бинарного поиска
    static void demonstrateSearch();
    
    // Демонстрация быстрой сортировки
    static void demonstrateSorting();
};

// Включение реализации
#include "../src/Menu.cpp"

#endif // MENU_H

