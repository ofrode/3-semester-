#include <iostream>
#include "../header/Functions.h"
#include "../header/LinkedList.h"

int main() {
    setlocale(LC_ALL, "ru");

    int typeChoice = 0;
    while (true) {
        std::cout << "\n=== Выберите тип данных списка ===\n";
        std::cout << "1. int\n";
        std::cout << "2. double\n";
        std::cout << "3. string\n";
        std::cout << "4. Выход\n";
        std::cout << "Ваш выбор: ";
        std::cin >> typeChoice;

        if (typeChoice == 4) {
            std::cout << "Завершение программы.\n";
            break;
        }

        switch (typeChoice) {
            case 1:
                runList<int>();
                break;
            case 2:
                runList<double>();
                break;
            case 3:
                runList<std::string>();
                break;
            default:
                std::cout << "Неверный выбор!\n";
        }
    }

    return 0;
}