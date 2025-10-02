#include "../headers/Chelnok.h"

using namespace std;

Chelnok::Chelnok(const std::string *addresses, int count) : addrCount(count)
{
    if (count > 0 && addresses)
    {
        purchaseAddresses = new std::string[count];
        for (int i = 0; i < count; ++i)
        {
            purchaseAddresses[i] = addresses[i];
        }
    }
}

Chelnok::~Chelnok()
{
    delete[] purchaseAddresses;
}

void Chelnok::inputChelnok()
{
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

void Chelnok::input()
{
    Tourist::input();
    Entrepreneur::inputEntrepreneur();
    Chelnok::inputChelnok();
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

void Chelnok::printInfoChelnok() const
{
    cout << "--- Адреса покупок ---" << endl;
    for (int i = 0; i < addrCount; i++)
        cout << "  " << purchaseAddresses[i] << endl;
}

void Chelnok::printInfo() const
{
    Tourist::printInfo();
    Entrepreneur::printEntrepreneur();
    Chelnok::printInfoChelnok();
}