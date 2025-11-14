#include "../hdr/Entrepreneur.h"
#include "../hdr/input.h"
#include <iostream>
using namespace std;

Entrepreneur::Entrepreneur() : Person() {}

Entrepreneur::Entrepreneur(const string &f, const string &l,
                           const string &m, int y,
                           int lic, const string &addr, int i)
    : Person(f, l, m, y),
      licenseNumber(lic),
      registrationAddress(addr),
      inn(i) {}

Entrepreneur::~Entrepreneur() {
    delete[] taxPayments;
}

Entrepreneur::Entrepreneur(const Entrepreneur& other)
    : Person(other),
      licenseNumber(other.licenseNumber),
      registrationAddress(other.registrationAddress),
      inn(other.inn),
      taxCount(other.taxCount),
      taxCapacity(other.taxCapacity) {
    if (taxCapacity > 0) {
        taxPayments = new pair<Date, float>[taxCapacity];
        for (int i = 0; i < taxCount; i++)
            taxPayments[i] = other.taxPayments[i];
    }
}

Entrepreneur& Entrepreneur::operator=(const Entrepreneur& other) {
    if (this == &other) return *this;
    Person::operator=(other);
    licenseNumber = other.licenseNumber;
    registrationAddress = other.registrationAddress;
    inn = other.inn;
    delete[] taxPayments;
    taxCount = other.taxCount;
    taxCapacity = other.taxCapacity;
    if (taxCapacity > 0) {
        taxPayments = new pair<Date, float>[taxCapacity];
        for (int i = 0; i < taxCount; i++)
            taxPayments[i] = other.taxPayments[i];
    } else {
        taxPayments = nullptr;
    }
    return *this;
}

Entrepreneur::Entrepreneur(Entrepreneur&& other) noexcept
    : Person(std::move(other)),
      licenseNumber(other.licenseNumber),
      registrationAddress(std::move(other.registrationAddress)),
      inn(other.inn),
      taxPayments(other.taxPayments),
      taxCount(other.taxCount),
      taxCapacity(other.taxCapacity) {
    other.taxPayments = nullptr;
    other.taxCount = 0;
    other.taxCapacity = 0;
}

Entrepreneur& Entrepreneur::operator=(Entrepreneur&& other) noexcept {
    if (this == &other) return *this;
    Person::operator=(std::move(other));
    licenseNumber = other.licenseNumber;
    registrationAddress = std::move(other.registrationAddress);
    inn = other.inn;
    delete[] taxPayments;
    taxPayments = other.taxPayments;
    taxCount = other.taxCount;
    taxCapacity = other.taxCapacity;
    other.taxPayments = nullptr;
    other.taxCount = 0;
    other.taxCapacity = 0;
    return *this;
}

static int inputPositiveIntSafely(const string& pt) {
    while (true) {
        try {
            return inputPosInt(pt);
        } catch (const InputOutOfRange& ex) {
            cout << "Вышел за ограничение: " << ex.what() << ". Попробуйте еще.\n";
        } catch (const InputError& ex) {
            cout << "Не INT: " << ex.what() << ". Попробуйте еще.\n";
        } catch (const system_error& ex) {
            cout << "Ошибка в системе: " << ex.what() << ". Попробуйте еще.\n";
        }
    }
}

static string inputLineSafely(const string& pt) {
    while (true) {
        try {
            return inputStr(pt);
        } catch (const InputOutOfRange& ex) {
            cout << "Вышел за ограничение: " << ex.what() << ". Попробуйте еще.\n";
        } catch (const InputError& ex) {
            cout << "Не INT: " << ex.what() << ". Попробуйте еще.\n";
        } catch (const system_error& ex) {
            cout << "Ошибка в системе: " << ex.what() << ". Попробуйте еще.\n";
        }
    }
}

void Entrepreneur::inputData() {
    while (true) {
        try {
            Person::inputData();
            licenseNumber = inputPositiveIntSafely("Введите лицензию: ");
            registrationAddress = inputLineSafely("Введите адресс регистрации: ");
            inn = inputPositiveIntSafely("Введите ИНН: ");
            break;
        } catch (const InputOutOfRange& ex) {
            cout << "Вышел за ограничение: " << ex.what() << ". Попробуйте еще.\n";
        } catch (const InputError& ex) {
            cout << "Не INT: " << ex.what() << ". Попробуйте еще.\n";
        } catch (const system_error& e) {
            cout << "Ошибка в системе: " << e.what() << ". Попробуйте еще.\n";
        }
    }
}


void Entrepreneur::printInfo() const {
    Person::printInfo();
    cout << "Лицензия: " << licenseNumber
         << ", ИНН: " << inn
         << ", Адресс регистрации: " << registrationAddress << endl;
}

int Entrepreneur::getLicenseNumber() const { return licenseNumber; }

std::string_view Entrepreneur::getRegistrationAddress() const { return registrationAddress; }

int Entrepreneur::getInn() const { return inn; }

void Entrepreneur::addTaxPayment(const Date& d, float sum) {
    while (taxCount >= taxCapacity) {
        ensureCapacity();
    }
    taxCount++;
    taxPayments[taxCount-1] = {d, sum};
}

void Entrepreneur::printTaxPayments() const {
    cout << "Налоговые платежи:\n";
    for (int i = 0; i < taxCount; i++) {
        taxPayments[i].first.printDate();
        cout << " - " << taxPayments[i].second << endl;
    }
}

void Entrepreneur::ensureCapacity() {
    int newCapacity = (taxCapacity == 0 ? 2 : taxCapacity * 2);
    auto* newArr = new pair<Date, float>[newCapacity];
    for (int i = 0; i < taxCount; i++) {
        newArr[i] = taxPayments[i];
    }
    delete[] taxPayments;
    taxPayments = newArr;
    taxCapacity = newCapacity;
}