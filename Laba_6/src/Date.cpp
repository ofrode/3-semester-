#include "../hdr/Date.h"
#include "../hdr/input.h"
#include <array>
#include <chrono>
#include <ctime>
#include <iostream>
using namespace std;

Date::Date() : day(1), month(1), year(2000) { getCurrentDate(); }

Date::Date(int d, int m, int y) : day(d), month(m), year(y) {
    getCurrentDate();
}

bool Date::isLeapYear(int y) {
    return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
}

bool Date::isValidDate(const int d,const int m,const int y) const {
    if (y < 1 || y > currentYear) return false;
    if (m < 1 || m > 12) return false;

    array<int, 12> daysInMonth = {31,28,31,30,31,30,31,31,30,31,30,31};
    if (isLeapYear(y)) daysInMonth[1] = 29;
    return (d >= 1 && d <= daysInMonth[m - 1]);
}

void Date::getCurrentDate() {
    using namespace std::chrono;
    const auto now = system_clock::now();
    time_t timeNow = system_clock::to_time_t(now);
    tm localTime{};
#ifdef _WIN32
    localtime_s(&localTime, &timeNow);
#else
    localtime_r(&timeNow, &localTime);
#endif
    currentDay = localTime.tm_mday;
    currentMonth = localTime.tm_mon + 1;
    currentYear = localTime.tm_year + 1900;
}

static int inputPositiveIntSafely(const string& pt) {
    while (true) {
        try {
            return inputPosInt(pt);
        } catch (const invalid_argument& ex) {
            cout << "Неизвестный аргумент: " << ex.what() << ". Попробуйте еще.\n";
        } catch (const out_of_range& ex) {
            cout << "Вышел за ограничения: " << ex.what() << ". Попробуйте еще.\n";
        } catch (const system_error& ex) {
            cout << "Ошибка в системе: " << ex.what() << ". Попробуйте еще.\n";
        }
    }
}

void Date::inputDate() {
    while (true) {
        try {
            cout << "Enter date:\n";
            int d = inputPositiveIntSafely("День: ");
            int m = inputPositiveIntSafely("Месяц: ");
            int y = inputPositiveIntSafely("Год: ");

            if (!isValidDate(d, m, y))
                throw invalid_argument("Invalid date values.");
            day = d;
            month = m;
            year = y;
            break;
        } catch (const invalid_argument& e) {
            cout << "Неизвестный аргумент: " << e.what() << ". Попробуйте еще.\n";
        } catch (const out_of_range& e) {
            cout << "Вышел за ограничения: " << e.what() << ". Попробуйте еще.\n";
        } catch (const system_error& e) {
            cout << "Ошибка в системе: " << e.what() << ". Попробуйте еще.\n";
        }
    }
}

void Date::printDate() const {
    cout << day << "." << month << "." << year;
}