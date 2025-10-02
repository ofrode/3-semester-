#include "../headers/Chelnok.h"

using namespace std;

Chelnok::~Chelnok()
{
    delete[] purchaseAddresses;
}

void Chelnok::input()
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

    cout << "Введите количество адресов покупок: ";
    cin >> addrCount;
    cin.ignore();
    purchaseAddresses = new string[addrCount];
    for (int i = 0; i < addrCount; i++)
    {
        cout << "  Адрес: ";
        getline(cin, purchaseAddresses[i]);
    }
}

void Chelnok::fillTestData()
{
    Entrepreneur::fillTestData();
    Tourist::fillTestData();
    addrCount = 2;
    purchaseAddresses = new string[addrCount];
    purchaseAddresses[0] = "г. Лида, ул. Лидская-Пивная, д.10";
    purchaseAddresses[1] = "г. Минск, пр. Держинского, д.20";
}

void Chelnok::printInfo() const
{
    Person::printInfo();

    cout << "--- Данные предпринимателя ---" << endl;
    cout << "Лицензия: " << licenseNumber
         << ", Адрес регистрации: " << registrationAddress
         << ", УНН: " << UNN << endl;
    for (int i = 0; i < taxCount; i++)
        cout << "  " << taxDates[i] << " - " << taxSums[i] << " руб." << endl;

    cout << "--- Данные туриста ---" << endl;
    cout << "Паспорт: " << passportData << endl;
    for (int i = 0; i < crossCount; i++)
        cout << "  " << crossDates[i] << " - " << crossCountries[i] << endl;

    cout << "--- Адреса покупок ---" << endl;
    for (int i = 0; i < addrCount; i++)
        cout << "  " << purchaseAddresses[i] << endl;
}