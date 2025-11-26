#ifndef MENU_H
#define MENU_H

#include "DoublyLinkedList.h"
#include "Algorithms.h"
#include <iostream>

class Menu
{
public:
    static void run();

private:
    static void printList(DoublyLinkedList<int> &list);

    static void showMenu();
    static void processChoice(DoublyLinkedList<int> &list, int choice);

    static void fillListManually(DoublyLinkedList<int> &list);
    static void fillListWithTestData(DoublyLinkedList<int> &list);

    static void sortList(DoublyLinkedList<int> &list);

    static void searchInList(DoublyLinkedList<int> &list);

    static void deleteElement(DoublyLinkedList<int> &list);
    static void clearList(DoublyLinkedList<int> &list);

    static void deleteFirstElement(DoublyLinkedList<int> &list);
    static void deleteLastElement(DoublyLinkedList<int> &list);
    static void deleteByValue(DoublyLinkedList<int> &list);
    static void deleteByPosition(DoublyLinkedList<int> &list);

    static void demonstrateListOperations();

    static void demonstrateIterator();

    static void demonstrateSearch();

    static void demonstrateSorting();
};

#include "../src/Menu.cpp"

#endif