#include "../headers/function.h"
#include "../../Laba_1/headers/check.h"
#include <iostream>
#include <limits>

void addWorker(Worker ***workers, int &count)
{
    int type;
    std::cout << "\n1. Почасовой\n2. Штатный\n3. С процентом\nВаш выбор: ";
    type = checkRange(1, 3);

    Worker **newArr = new Worker *[count + 1];

    for (int i = 0; i < count; ++i)
        newArr[i] = (*workers)[i];

    delete[] *workers;
    *workers = newArr;

    Worker *newWorker = nullptr;

    switch (type)
    {
    case 1:
        newWorker = new HourlyWorker();
        break;
    case 2:
        newWorker = new StaffWorker();
        break;
    case 3:
        newWorker = new CommissionWorker();
        break;
    default:
        std::cout << "Неверный тип.\n";
        return;
    }

    newWorker->inputData();
    (*workers)[count++] = newWorker;
}

void showWorkers(Worker **workers, int count)
{
    if (count == 0)
    {
        std::cout << "Нет работников.\n";
        return;
    }
    for (int i = 0; i < count; ++i)
    {
        std::cout << "\nРаботник #" << (i + 1) << ":\n";
        workers[i]->printInfo();
    }
}

void deleteAll(Worker **workers, int count)
{
    for (int i = 0; i < count; ++i)
        delete workers[i];
}