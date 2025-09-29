#include "../headers/functions.h"

using namespace std;

void clearInputBuffer()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int menu()
{
    int choice;
    cout << "\n1 - Ввести первую строку\n";
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

void inputString(String &str1, String &str2)
{
    int choice;
    cout << "\nВведите первую строку: ";
    cin >> str1;

    cout << "\nВы хотите скопировать первую строку (1) или написать что-то другое (2): ";
    cin >> choice;
    clearInputBuffer();

    if (choice == 1)
    {
        str2 = str1;
        cout << "\nВторая строка скопирована из первой.\n";
    }
    else
    {
        cout << "\nВведите вторую строку: ";
        cin >> str2;
    }
    cout << "\nСтроки введены!!!\nВведите Enter для продолжения";
}

void concatenateString(const String &str1, const String &str2)
{
    String result;
    int choice;
    cout << "\nВыберите как складывать строки: 1 - С пробелом, 2 - Без пробела: ";
    cin >> choice;
    clearInputBuffer();

    if (choice == 1)
    {
        result = str1;
        result += " ";
        result += str2;
    }
    else
    {
        result = str1;
        result += str2;
    }
    cout << "\nСтроки сложены!!!\n";
    cout << "Ваша итоговая строка: " << result << "\nВведите Enter для продолжения";
}

void multiplyString(String &str1, String &str2)
{
    String result;
    int choice;
    int count;
    cout << "\nСколько раз надо просуммировать: ";
    cin >> count;
    clearInputBuffer();

    cout << "\nКакую строку хотите просуммировать (1 или 2): ";
    cin >> choice;
    clearInputBuffer();

    if (choice == 1)
    {
        result = concatenateStringMultipleTimes(str1, count);
        cout << "\nСтрока сложена сама с собой " << count << " раз!!!\n";
        cout << "Ваша итоговая строка: " << result << "\nВведите Enter для продолжения";
    }
    else
    {
        result = concatenateStringMultipleTimes(str2, count);
        cout << "\nСтрока сложена сама с собой " << count << " раз!!!\n";
        cout << "Ваша итоговая строка: " << result << "\nВведите Enter для продолжения";
    }
}
