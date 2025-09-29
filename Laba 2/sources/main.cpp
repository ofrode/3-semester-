#include "../headers/string.h"
#include "../headers/function.h"
#include <iostream>

using namespace std;

int main()
{
    int choice;
    String str1;
    String str2;
    String str3;

    while (true)
    {
        choice = menu();

        switch (choice)
        {
        case 1:
                inputString(str1, str2);
            break;

        case 2:
                sumString(str1, str2, str3);
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
        clearInputBuffer();
        cout << "\nНажмите Enter для продолжения\n";
    }
}