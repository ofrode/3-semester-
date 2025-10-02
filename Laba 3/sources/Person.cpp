#include "../headers/Person.h"

using namespace std;

void Person::input()
{
    cout << "Введите фамилию: ";
    cin >> lastName;
    cout << "Введите имя: ";
    cin >> firstName;
    cout << "Введите отчество: ";
    cin >> patronymic;
    cout << "Введите год рождения: ";
    cin >> birthYear;
}

void Person::fillTestData()
{
    lastName = "Апанас";
    firstName = "Жека";
    patronymic = "Эдуардович";
    birthYear = 2007;
}

void Person::printInfo() const
{
    cout << lastName << " " << firstName << " " << patronymic << ", год рождения: " << birthYear << endl;
}