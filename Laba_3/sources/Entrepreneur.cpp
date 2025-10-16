#include "../headers/Entrepreneur.h"

using namespace std;

Entrepreneur::Entrepreneur(Entrepreneur &&other) noexcept : Person(other), licenseNumber(move(other.licenseNumber)), registrationAddress(move(other.registrationAddress)),
                                                            UNN(move(other.UNN)), taxDates(other.taxDates), taxSums(other.taxSums), taxCount(other.taxCount)
{
    other.taxDates = nullptr;
    other.taxSums = nullptr;
    other.taxCount = 0;
}

Entrepreneur &Entrepreneur::operator=(Entrepreneur &&other) noexcept
{
    if (this != &other)
    {

        delete[] taxDates;
        delete[] taxSums;

        licenseNumber = move(other.licenseNumber);
        registrationAddress = move(other.registrationAddress);
        UNN = move(other.UNN);
        taxDates = other.taxDates;
        taxSums = other.taxSums;
        taxCount = other.taxCount;

        other.taxDates = nullptr;
        other.taxSums = nullptr;
        other.taxCount = 0;
    }
    return *this;
}

Entrepreneur::~Entrepreneur()
{
    delete[] taxDates;
    delete[] taxSums;
}

void Entrepreneur::inputEntrepreneur()
{
    cout << "Введите номер лицензии: ";
    cin >> licenseNumber;
    cout << "Введите адрес регистрации: ";
    cin.ignore();
    getline(cin, registrationAddress);
    cout << "Введите УНН: ";
    cin >> UNN;

    cout << "Введите количество налоговых платежей: ";
    taxCount = checkRange(1, 100);
    taxDates = new string[taxCount];
    taxSums = new double[taxCount];

    for (int i = 0; i < taxCount; i++)
    {
        cout << "  Дата платежа: ";
        cin >> taxDates[i];
        cout << "  Сумма: ";
        taxSums[i] = checkRange(0.0f, 1000000.0f);
    }
}

void Entrepreneur::input()
{
    Person::input();
    inputEntrepreneur();
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

void Entrepreneur::printEntrepreneur() const
{
    cout << "Лицензия: " << licenseNumber
         << ", Адрес регистрации: " << registrationAddress
         << ", УНН: " << UNN << endl;
    for (int i = 0; i < taxCount; i++)
        cout << "  " << taxDates[i] << " - " << taxSums[i] << " руб." << endl;
}

void Entrepreneur::printInfo() const
{
    Person::printInfo();
    Entrepreneur::printEntrepreneur();
}