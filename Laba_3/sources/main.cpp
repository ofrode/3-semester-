#include <iostream>
#include <string>
#include "../headers/Person.h"
#include "../headers/Tourist.h"
#include "../headers/Entrepreneur.h"
#include "../headers/Chelnok.h"
#include "../headers/functions.h"

using namespace std;

int main()
{
    system("clear");
    setlocale(LC_ALL, "ru_RU.UTF-8");

    Person **people = nullptr;
    int count = 0;

    int choice;
    while (true)
    {
        cout << "\n=== МЕНЮ ===\n";
        cout << "1 - Создать список людей\n";
        cout << "2 - Добавить человека\n";
        cout << "3 - Просмотреть всех\n";
        cout << "0 - Выход\n";
        cout << "Ваш выбор: ";
        choice = checkRange(0, 3);

        switch (choice)
        {
        case 1:
            createList(people, count);
            break;
        case 2:
            addPerson(people, count);
            break;
        case 3:
            printAll({people, static_cast<std::size_t>(count)});
            break;
        case 0:
            for (int i = 0; i < count; i++)
            {
                delete people[i];
            }
            delete[] people;
            return 0;
        default:
            cout << "Программа завершена с ошибкой";
            for (int i = 0; i < count; i++)
            {
                delete people[i];
            }
            delete[] people;
            return 0;
        }

    }
}