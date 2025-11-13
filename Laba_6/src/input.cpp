#include "../hdr/input.h"

#include <algorithm>
#include <format>
#include <iostream>
#include <regex>
#include <sstream>
#include <stdexcept>
#include <string>

using namespace std;

inline void trimInplace(string &s) {
    while (!s.empty() && isspace(static_cast<unsigned char>(s.front())))
        s.erase(s.begin());
    while (!s.empty() && isspace(static_cast<unsigned char>(s.back())))
        s.pop_back();
}

string readLineTrimmed(const string &pt) {
    cout << pt;
    string input;
    getline(cin, input);
    trimInplace(input);
    return input;
}

int inputInt(const string &pt) {
    string input = readLineTrimmed(pt);

    regex pat(R"(^[+-]?\d+$)");
    if (!regex_match(input, pat))
        throw InputError(std::format("Не целочисленный ввод: '{}'", input));

    try {
        return stoi(input);
    } catch (const invalid_argument &) {
        throw InputError(std::format("Не целочисленный ввод: '{}'", input));
    } catch (const out_of_range &) {
        throw InputError(std::format("Выход за границы: '{}'", input));
    }
}

int inputPosInt(const string &pt) {
    int number = inputInt(pt);
    if (number <= 0)
        throw InputError(std::format("Число должно быть положительным {}", number));
    return number;
}

float inputFloat(const string &pt) {
    string input = readLineTrimmed(pt);
    regex pat(R"(^[+-]?\d+([.,]\d+)?$)");

    if (!regex_match(input, pat))
        throw InputError(std::format("Неизвестный аргумент: '{}'", input));

    ranges::replace(input, ',', '.');

    stringstream ss(input);
    ss.imbue(locale::classic());
    float value;
    ss >> value;

    if (!ss || !ss.eof())
        throw InputError(std::format("Неизвестный аргумент: '{}'", input));

    return value;
}

float inputPosFloat(const string &pt) {
    float number = inputFloat(pt);
    if (number <= 0.0f)
        throw InputError(std::format("Число должно быть положительным {:.2f}", number));
    return number;
}

string inputStr(const string &pt) {
    string input = readLineTrimmed(pt);
    if (input.empty())
        throw InputError("Не может быть пустым.");
    return input;
}

string inputWord(const string &pt) {
    string input = readLineTrimmed(pt);
    regex pat(R"(^\S+$)");
    if (!regex_match(input, pat))
        throw InputError(std::format("Неправильный ввод слова: '{}'", input));
    return input;
}