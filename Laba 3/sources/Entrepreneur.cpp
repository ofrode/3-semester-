#include "../headers/Entrepreneur.h"

using namespace std;

Entrepreneur::Entrepreneur(const Entrepreneur &other) : Person(other), licenseNumber(other.licenseNumber), registrationAddress(other.registrationAddress),
                                                        UNN(other.UNN), taxDates(nullptr), taxSums(nullptr), taxCount(other.taxCount)
{
    if (taxCount > 0)
    {
        taxDates = new std::string[taxCount];
        taxSums = new double[taxCount];

        for (int i = 0; i < taxCount; ++i)
        {
            taxDates[i] = other.taxDates[i];
            taxSums[i] = other.taxSums[i];
        }
    }
}

Entrepreneur::~Entrepreneur()
{
    delete[] taxDates;
    delete[] taxSums;
}

void Entrepreneur::input()
{
    Person::input();
    cout << "Введите номер лицензии: ";
    cin >> licenseNumber;
    cout << "Введите адрес регистрации: ";
    cin.ignore();
    getline(cin, registrationAddress);
    cout << "Введите УНН: ";
    cin >> UNN;

    cout << "Введите количество налоговых платежей: ";
    cin >> taxCount;
    taxDates = new string[taxCount];
    taxSums = new double[taxCount];

    for (int i = 0; i < taxCount; i++)
    {
        cout << "  Дата платежа: ";
        cin >> taxDates[i];
        cout << "  Сумма: ";
        cin >> taxSums[i];
    }
}

void Entrepreneur::fillTestData()
{
    Person::fillTestData();
    licenseNumber = "12345";
    registrationAddress = "г. Лида, ул. Апанаса-Лидская-Пивная, д.52";
    UNN = "7701234567";

    taxCount = 2;
    taxDates = new string[taxCount];
    taxSums = new double[taxCount];
    taxDates[0] = "01.01.2025";
    taxSums[0] = 1000;
    taxDates[1] = "01.02.2025";
    taxSums[1] = 2000;
}

void Entrepreneur::printInfo() const
{
    Person::printInfo();
    cout << "Лицензия: " << licenseNumber
         << ", Адрес регистрации: " << registrationAddress
         << ", УНН: " << UNN << endl;
    for (int i = 0; i < taxCount; i++)
        cout << "  " << taxDates[i] << " - " << taxSums[i] << " руб." << endl;
}