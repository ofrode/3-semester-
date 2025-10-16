#include "../headers/check.h"
#include "../headers/employee.h"
#include <iostream>

using namespace std;

void Employee::getEmploy()
{
    using enum Etype;

    cout << "Введите номер сотрудника: ";
    number = checkRange(1, 1000000);

    cout << "Введите оклад сотрудника: ";
    salary = checkRange(0.0f, 1000000.0f);

    cout << "Введите дату приема на работу (день месяц год): ";
    hireDate.day = checkRange(1, 31);
    hireDate.month = checkRange(1, 12);
    hireDate.year = checkRange(1900, 2011);

    char employeeType;
    cout << "Введите тип сотрудника (l - лаборант, s - секретарь, m - менеджер, d - директор): ";
    while (true)
    {
        cin >> employeeType;
        if (employeeType == 'l' || employeeType == 's' || employeeType == 'm' || employeeType == 'd')
            break;
        cout << "Ошибка. Попробуйте еще раз.\n";
    }

    switch (employeeType)
    {
    case 'l':
        type = LABORANT;
        break;
    case 's':
        type = SECRETARY;
        break;
    case 'm':
        type = MANAGER;
        break;
    case 'd':
        type = DIRECTOR;
        break;
    default:
        type = LABORANT;
        break;
    }
}

void Employee::putEmploy() const
{
    using enum Etype;

    cout << "\nИнформация о сотруднике:" << endl;
    cout << "Номер: " << number << endl;
    cout << "Оклад: " << salary << endl;
    cout << "Дата приема на работу: ";
    if (hireDate.day < 10) cout << "0";
    cout << hireDate.day << ".";
    if (hireDate.month < 10) cout << "0";
    cout << hireDate.month << "." << hireDate.year << endl;
    cout << "Должность: ";

    switch (type)
    {
    case LABORANT:
        cout << "лаборант";
        break;
    case SECRETARY:
        cout << "секретарь";
        break;
    case MANAGER:
        cout << "менеджер";
        break;
    case DIRECTOR:
        cout << "директор";
        break;
    }
    cout << endl;
}
