#include "../hdr/Person.h"
#include "../hdr/input.h"
#include <iostream>
#include <chrono>
using namespace std;

Person::Person() : firstName(""), lastName(""), middleName(""), birthYear(2000) {}

Person::Person(const string& f, const string& l,
               const string& m, int y)
    : firstName(f), lastName(l), middleName(m), birthYear(y) {}

string_view Person::getFirstName() const { return firstName; }
string_view Person::getLastName() const { return lastName; }
string_view Person::getMiddleName() const { return middleName; }
int Person::getBirthYear() const { return birthYear; }

void Person::setFirstName(string_view f) { firstName = f; }
void Person::setLastName(string_view l) { lastName = l; }
void Person::setMiddleName(string_view m) { middleName = m; }
void Person::setBirthYear(int y) { birthYear = y; }

static string inputWordSafely(const string& pt) {
    while (true) {
        try {
            return inputWord(pt);
        } catch (const InputError& ex) {
            cout << "Неизвестный аргумент: " << ex.what() << ". Попробуйте еще.\n";
        } catch (const out_of_range& ex) {
            cout << "Вышел за ограничения: " << ex.what() << ". Попробуйте еще.\n";
        } catch (const system_error& ex) {
            cout << "Ошибка в системе: " << ex.what() << ". Попробуйте еще.\n";
        }
    }
}

static int inputPositiveIntSafely(const string& pt) {
    while (true) {
        try {
            return inputPosInt(pt);
        } catch (const InputError& ex) {
            cout << "Неизвестный аргумент: " << ex.what() << ". Попробуйте еще.\n";
        } catch (const out_of_range& ex) {
            cout << "Вышел за ограничения: " << ex.what() << ". Попробуйте еще.\n";
        } catch (const system_error& ex) {
            cout << "Ошибка в системе: " << ex.what() << ". Попробуйте еще.\n";
        }
    }
}

void Person::inputData() {
    while (true) {
        try {
            firstName = inputWordSafely("Введите имя: ");
            lastName = inputWordSafely("Введите фамилию: ");
            middleName = inputWordSafely("Ввведите отчество: ");

            int y = inputPositiveIntSafely("Введите год рождения: ");
            const auto now = chrono::system_clock::now();
            time_t tt = chrono::system_clock::to_time_t(now);
            tm tmv{};
#ifdef _WIN32
            localtime_s(&tmv, &tt);
#else
            localtime_r(&tt, &tmv);
#endif
            int currentYear = tmv.tm_year + 1900;
            if (y > currentYear) throw InputError("Не может быть будущий год.");

            birthYear = y;
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

void Person::printInfo() const {
    cout << lastName << " " << firstName << " " << middleName
         << ", Рожден " << birthYear << endl;
}