#include "../headers/Hourly.h"
#include "../../Laba_1/headers/check.h"
#include <iostream>

double HourlyWorker::calculateSalary() const
{
    return hours * rate;
}

void HourlyWorker::inputData()
{
    Worker::inputData();
    std::cout << "Введите количество часов: ";
    hours = checkRange(0, 744);
    std::cout << "Введите ставку за час: ";
    rate = checkRange(1.0f, 1000.0f);
}

void HourlyWorker::printInfo() const
{
    Worker::printInfo();
    std::cout << "Тип: Почасовой работник\n"
              << "Часы: " << hours << "\n"
              << "Ставка: " << rate << "\n"
              << "Зарплата: " << calculateSalary() << "\n";
}