#include "../headers/function.h"
#include "../headers/string.h"
#include <iostream>
#include <limits>

using namespace std;

void clearInputBuffer()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int menu()
{
    int choice;
    cout << "1 - Ввести первую строку\n";
    cout << "2 - Сложить строки\n";
    cout << "3 - Сложить строку саму с собой\n";
    cout << "4 - Выход\n";
    cout << "Выберите действие: ";
    cin >> choice;
    clearInputBuffer();
    return choice;
}

String concatenateStringMultipleTimes(const String &original, int count)
{
    if (count <= 0)
        return String();
    if (count == 1)
        return original;

    String result = original;
    for (int i = 1; i < count; i++)
    {
        result += original;
    }
    return result;
}

void inputString(String& str1, String& str2)
{
    int choice;
    cout << "\nВведите первую строку: ";
    cin >> str1;
    clearInputBuffer();

    cout << "\nВы хотите скопировать первую строку (1) или написать что-то другое (2): ";
    cin >> choice;
    clearInputBuffer();

    if (choice == 1)
    {
        str2 = str1;
        cout << "Вторая строка скопирована из первой.\n";
    }
    else
    {
        cout << "\nВведите вторую строку: ";
        cin >> str2;
    }
    cout << "\nСтроки введены!!!\n";
    cout << "\nНажмите Enter для продолжения\n";
}

void sumString(const String& str1, const String& str2, String& str3)
{
    int choice;
    cout << "Выберите как складывать строки: 1 - С пробелом, 2 - Без пробела: ";
    cin >> choice;
    clearInputBuffer();

    if (choice == 1)
    {
        str3 = str1 + "  " + str2;
    }
    else
    {
        str3 = str1 + str2;
    }
    cout << "\nСтроки сложены!!!\n";
    cout << "Ваша итоговая строка: " << str3 << "\n";
}

void multiplyString(String& str1, String& str2)
{   
    int choice;
    int count;
    cout << "\nСколько раз надо просуммировать: ";
    cin >> count;
    clearInputBuffer();

    cout << "Какую строку хотите просуммировать (1 или 2): ";
    cin >> choice;
    clearInputBuffer();
    if (choice == 1)
    {
        clearInputBuffer();
        str1 = concatenateStringMultipleTimes(str1, count);
        cout << "\nСтрока сложена сама с собой " << count << " раз!!!\n";
        cout << "Ваша итоговая строка: " << str1 << "\n";
    }
    else
    {
        clearInputBuffer();
        str2 = concatenateStringMultipleTimes(str2, count);
        cout << "\nСтрока сложена сама с собой " << count << " раз!!!\n";
        cout << "Ваша итоговая строка: " << str2 << "\n";
    }
}