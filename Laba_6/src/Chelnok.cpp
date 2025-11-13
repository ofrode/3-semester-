#include "../hdr/Chelnok.h"
#include "../hdr/input.h"
#include <iostream>
#include <format>
#include <stdexcept>

using namespace std;

Shuttler::Shuttler() : Person(), Entrepreneur(), Tourist() {}

Shuttler::~Shuttler() {
    delete[] shoppingAddresses;
}

Shuttler::Shuttler(const Shuttler& other)
    : Person(other),
      Entrepreneur(other),
      Tourist(other),
      shopCount(other.shopCount),
      shopCapacity(other.shopCapacity) {
    if (shopCapacity > 0) {
        shoppingAddresses = new string[shopCapacity];
        for (int i = 0; i < shopCount; i++) {
            shoppingAddresses[i] = other.shoppingAddresses[i];
        }
    }
}

Shuttler& Shuttler::operator=(const Shuttler& other) {
    if (this == &other) return *this;
    Entrepreneur::operator=(other);
    Tourist::operator=(other);
    delete[] shoppingAddresses;
    shopCount = other.shopCount;
    shopCapacity = other.shopCapacity;
    if (shopCapacity > 0) {
        shoppingAddresses = new string[shopCapacity];
        for (int i = 0; i < shopCount; i++) {
            shoppingAddresses[i] = other.shoppingAddresses[i];
        }
    } else {
        shoppingAddresses = nullptr;
    }
    return *this;
}

Shuttler::Shuttler(Shuttler&& other) noexcept
    : Person(std::move(other)),
      Entrepreneur(std::move(other)),
      Tourist(std::move(other)),
      shoppingAddresses(other.shoppingAddresses),
      shopCount(other.shopCount),
      shopCapacity(other.shopCapacity) {
    other.shoppingAddresses = nullptr;
    other.shopCount = 0;
    other.shopCapacity = 0;
}

Shuttler& Shuttler::operator=(Shuttler&& other) noexcept {
    if (this == &other) return *this;
    Entrepreneur::operator=(std::move(other));
    Tourist::operator=(std::move(other));
    delete[] shoppingAddresses;
    shoppingAddresses = other.shoppingAddresses;
    shopCount = other.shopCount;
    shopCapacity = other.shopCapacity;
    other.shoppingAddresses = nullptr;
    other.shopCount = 0;
    other.shopCapacity = 0;
    return *this;
}

void Shuttler::ensureCapacity() {
    int newCapacity = (shopCapacity == 0 ? 2 : shopCapacity * 2);
    auto* newArr = new string[newCapacity];
    for (int i = 0; i < shopCount; i++) {
        newArr[i] = shoppingAddresses[i];
    }
    delete[] shoppingAddresses;
    shoppingAddresses = newArr;
    shopCapacity = newCapacity;
}

void Shuttler::addShoppingAddress(std::string_view address) {
    while (shopCount >= shopCapacity) {
        ensureCapacity();
    }
    shopCount++;
    shoppingAddresses[shopCount - 1] = string(address);
}

void Shuttler::printShoppingAddresses() const {
    cout << "Shopping addresses:\n";
    for (int i = 0; i < shopCount; i++) {
        cout << "- " << shoppingAddresses[i] << endl;
    }
}

string Shuttler::inputShoppingAddress(int index) const {
    while (true) {
        try {
            return inputStr(std::format("Address {}: ", index + 1));
        } catch (const InputError& ex) {
            cout << "Неизвестный аргумент: " << ex.what() << ". Попробуйте еще.\n";
        } catch (const out_of_range& ex) {
            cout << "Вышел за ограничения: " << ex.what() << ". Попробуйте еще.\n";
        } catch (const system_error& ex) {
            cout << "Ошибка в системе: " << ex.what() << ". Попробуйте еще.\n";
        }
    }
}

void Shuttler::inputData() {
    while (true) {
        try {
            Entrepreneur::inputData();
            setPassportData(inputWord("Введите паспортные данные: "));

            int n = inputPosInt("Введите количество покупок ");
            for (int i = 0; i < n; i++) {
                string addr = inputShoppingAddress(i);
                addShoppingAddress(addr);
            }

            break;
        } catch (const InputError& e) {
            cout << "Неизвестный аргумент: " << e.what() << ". Попробуйте еще.\n";
        } catch (const out_of_range& e) {
            cout << "Вышел за ограничения: " << e.what() << ". Попробуйте еще.\n";
        } catch (const system_error& e) {
            cout << "Ошибка в системе: " << e.what() << ". Попробуйте еще.\n";
        }
    }
}

void Shuttler::printInfo() const {
    cout << "\nЧелнок\n";
    Person::printInfo();
    cout << "Лицензия: " << getLicenseNumber()
         << ", ИНН: " << getInn()
         << ", Адресс регистрации: " << getRegistrationAddress() << endl;
    cout << "Паспортные данные: " << getPassportData() << endl;
    printShoppingAddresses();
}