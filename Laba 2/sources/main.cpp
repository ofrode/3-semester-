#include <iostream>
#include <locale>
#include "../headers/string.h"
#include "../headers/functions.h"

using namespace std;

int main()
{
    system("clear");
    setlocale(LC_ALL, "ru_RU.UTF-8");

    int choice;
    String str1;
    String str2;

    while (true)
    {
        choice = menu();

        switch (choice)
        {
        case 1:
            inputString(str1, str2);
            break;

        case 2:
            concatenateString(str1, str2);
            break;

        case 3:
            multiplyString(str1, str2);
            break;
        case 4:
            return 0;
        default:
            cout << "Неверный выбор!\n";
            break;
        }
    }
}
