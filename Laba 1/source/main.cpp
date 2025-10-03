#include "../headers/function.h"
#include "../headers/check.h"
#include "../headers/employee.h"
#include <iostream>

using namespace std;

int main()
{
    int numEmployees = 0;
    int chois;
    Employee *employees;
    while (true)
    {
        cout << "Лабораторная работа №1\n\n";
        cout << "1 - Создать первого сотрудника\n";
        cout << "2 - Добавить еще сотрудников\n";
        cout << "3 - Просмотреть список сотрудников\n";
        cout << "4 - Выйти из программы\n";
        cout << "Ваш выбор: ";
        chois = checkRange(1, 4);
        switch (chois)
        {
        case 1:
            createFirstEmployee(numEmployees, employees);
            break;
        case 2:
            addMoreEmployees(numEmployees, employees);
            break;
        case 3:
            displayEmployees(numEmployees, employees); 
            break;
        case 4:
            if (numEmployees != 0)
            {
                delete[] employees;
            }
            return 0;
        }
    }
}