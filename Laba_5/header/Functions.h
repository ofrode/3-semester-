#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include"LinkedList.h"

void menu();

template <typename T>
void runList() {
    LinkedList<T> list;
    int choice = 0;

    while (choice != 6) {
        menu();
        std::cin >> choice;

        switch (choice) {
            case 1: {
                T value;
                std::cout << "Введите элемент: ";
                std::cin >> value;
                list.pushFront(value);
                break;
            }
            case 2:
                list.popFront();
                break;
            case 3:
                list.print();
                break;
            case 4:
                list.clear();
                std::cout << "Список очищен.\n";
                break;
            case 5:
                std::cout << "Размер списка: " << list.getSize() << "\n";
                break;
            case 6:
                std::cout << "Выход в главное меню.\n";
                break;
            default:
                std::cout << "Неверный выбор. Попробуйте снова.\n";
        }
    }
}


#endif