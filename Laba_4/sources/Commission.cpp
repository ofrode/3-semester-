#include "../headers/Commission.h"
#include "../../Laba_1/headers/check.h"
#include <iostream>

double CommissionWorker::calculateSalary() const
{
    return sales * percent / 100.0;
}

void CommissionWorker::inputData()
{
    Worker::inputData();
    std::cout << "Введите сумму продаж: ";
    sales = checkRange(0.0f, 10000000.0f);
    std::cout << "Введите процентную ставку: ";
    percent = checkRange(1.0f, 100.0f);
}

void CommissionWorker::printInfo() const
{
    Worker::printInfo();
    std::cout << "Тип: Работник с процентной оплатой\n"
              << "Продажи: " << sales << "\n"
              << "Процент: " << percent << "%\n"
              << "Зарплата: " << calculateSalary() << "\n";
}