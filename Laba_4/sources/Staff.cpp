#include "../headers/Staff.h"
#include "../../Laba_1/headers/check.h"
#include <iostream>

double StaffWorker::calculateSalary() const
{
    return fixedSalary;
}

void StaffWorker::inputData()
{
    Worker::inputData();
    std::cout << "Введите фиксированную зарплату: ";
    fixedSalary = checkRange(567.0f, 10000000.0f);
}

void StaffWorker::printInfo() const
{
    Worker::printInfo();
    std::cout << "Тип: Штатный работник\n"
              << "Фиксированная зарплата: " << fixedSalary << "\n";
}