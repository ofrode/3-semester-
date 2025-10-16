#include "../headers/function.h"
#include "../headers/check.h"
#include <iostream>

using namespace std;

void createFirstEmployee(int &numEmployees, Employee *&employees)
{
    if (numEmployees == 0)
    {
        numEmployees = 1;
        employees = new Employee[numEmployees];
        employees[numEmployees - 1].getEmploy();
        cout << "\nСотрудник создан\n";
    }
    else
    {
        cout << "\nПервый сотрудник был уже добавлен, если нужны еще сотрудники то выберете в меню цифру 2\n";
    }
}

void addMoreEmployees(int &numEmployees, Employee *&employees)
{
    int newNumEmployees;
    Employee *newEmployees;

    cout << "\nВведите количество сотрудников которых хотите добавить: ";
    newNumEmployees = checkRange(1, 1000000);
    newEmployees = new Employee[numEmployees + newNumEmployees];

    for (int i = 0; i < numEmployees; i++)
    {
        newEmployees[i] = Employee(employees[i]);
    }

    delete[] employees;
    employees = newEmployees;

    for (int i = numEmployees; i < newNumEmployees + numEmployees; i++)
    {
        employees[i].getEmploy();
        cout << "\nСотрудник создан\n";
    }

    numEmployees += newNumEmployees;
}

void displayEmployees(const int numEmployees, Employee *&employees)
{
    cout << "\n=== ИНФОРМАЦИЯ О СОТРУДНИКАХ ===\n";
    if (numEmployees == 0)
    {
        cout << "Нет сотрудников\n";
        return;
    }

    for (int i = 0; i < numEmployees; i++)
    {
        employees[i].putEmploy();
        cout << "------------------------\n";
    }
}