#include "../headers/Chelnok.h"

using namespace std;

Chelnok::Chelnok(Chelnok &&other) noexcept : Entrepreneur(std::move(other)), Tourist(std::move(other)), purchaseAddresses(other.purchaseAddresses), addrCount(other.addrCount)
{
    other.purchaseAddresses = nullptr;
    other.addrCount = 0;
}

Chelnok &Chelnok::operator=(Chelnok &&other) noexcept
{
    if (this != &other)
    {
        Entrepreneur::operator=(std::move(other));
        Tourist::operator=(std::move(other));

        delete[] purchaseAddresses;

        purchaseAddresses = other.purchaseAddresses;
        addrCount = other.addrCount;

        other.purchaseAddresses = nullptr;
        other.addrCount = 0;
    }
    return *this;
}

Chelnok::~Chelnok()
{
    delete[] purchaseAddresses;
}

void Chelnok::inputChelnok()
{
    cout << "Введите количество адресов покупок: ";
    addrCount = checkRange(1,100);
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