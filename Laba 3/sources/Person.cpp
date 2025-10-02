#include "../headers/Person.h"

using namespace std;

Person &Person::operator=(const Person &&other) noexcept
{
    if (this != &other)
    {
        firstName = std::move(other.firstName);
        lastName = std::move(other.lastName);
        patronymic = std::move(other.patronymic);
        birthYear = other.birthYear;
    }
    return *this;
}

void Person::input()
{
    cout << "Введите фамилию: ";
    cin >> lastName;
    cout << "Введите имя: ";
    cin >> firstName;
    cout << "Введите отчество: ";
    cin >> patronymic;
    cout << "Введите год рождения: ";
    birthYear = checkRange(1900, 2025);
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