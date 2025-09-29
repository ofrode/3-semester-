#include "../headers/check.h"
#include <limits>
#include <iostream>

using namespace std;

template <typename T>
T getValidatedInput(const string &errorMessage)
{
    T value;
    while (true)
    {
        cin >> value;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка! " << errorMessage << endl;
        }
        else if (cin.peek() != '\n')
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка! Введите только число без лишних символов." << endl;
        }
        else
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}

int getInput(int)
{
    return getValidatedInput<int>("Введите целое число.");
}

float getInput(float)
{
    return getValidatedInput<float>("Введите число.");
}

template <typename T>
T validateRange(T min, T max, const string &typeName)
{
    T value;
    while (true)
    {
        value = getInput(T());
        if (value >= min && value <= max)
        {
            return value;
        }
        cout << "Ошибка. Введите " << typeName << " в диапазоне от " << min << " до " << max << ". Попробуйте еще раз.\n";
    }
}

int checkRange(int min, int max)
{
    return validateRange(min, max, "целое число");
}

float checkRange(float min, float max)
{
    return validateRange(min, max, "число");
}