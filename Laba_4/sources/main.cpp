#include <iostream>
#include "../headers/Hourly.h"
#include "../headers/Staff.h"
#include "../headers/Commission.h"
#include "../headers/function.h"
#include "../../Laba_1/headers/check.h"

int main()
{
    Worker **workers = nullptr;
    size_t count = 0;

    int choice;
    while (true)
    {
        std::cout << "\n=== МЕНЮ ===\n"
                  << "1. Добавить работника\n"
                  << "2. Показать всех работников\n"
                  << "0. Выход\n"
                  << "Ваш выбор: ";
        choice = checkRange(0, 2);

        switch (choice)
        {
        case 1:
            addWorker(&workers, count);
            break;
        case 2:
            showWorkers({workers, count});
            break;
        case 0:
            deleteAll(workers, count);
            delete[] workers;
            return 0;
        default:
            std::cout << "Неверный выбор.\n";
            break;
        }
    }
}