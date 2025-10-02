#include "../headers/Tourist.h"

using namespace std;

Tourist::~Tourist()
{
    delete[] crossDates;
    delete[] crossCountries;
}

void Tourist::input()
{
    Person::input();
    cout << "Введите данные паспорта: ";
    cin >> passportData;

    cout << "Введите количество пересечений границы: ";
    cin >> crossCount;
    crossDates = new string[crossCount];
    crossCountries = new string[crossCount];

    for (int i = 0; i < crossCount; i++)
    {
        cout << "  Дата: ";
        cin >> crossDates[i];
        cout << "  Страна: ";
        cin >> crossCountries[i];
    }
}

void Tourist::fillTestData()
{
    Person::fillTestData();
    passportData = "1234567890";
    crossCount = 2;
    crossDates = new string[crossCount];
    crossCountries = new string[crossCount];
    crossDates[0] = "01.03.2025";
    crossCountries[0] = "Франция";
    crossDates[1] = "15.04.2025";
    crossCountries[1] = "Германия";
}

void Tourist::printInfo() const
{
    Person::printInfo();
    cout << "Паспорт: " << passportData << endl;
    for (int i = 0; i < crossCount; i++)
        cout << "  " << crossDates[i] << " - " << crossCountries[i] << endl;
}
