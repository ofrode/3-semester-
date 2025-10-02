#include "../headers/functions.h"

using namespace std;

Person *createPerson()
{
    int type;
    cout << "Выберите тип человека:\n";
    cout << "1 - Предприниматель\n";
    cout << "2 - Турист\n";
    cout << "3 - Челнок\n";
    cout << "Ваш выбор: ";
    type = checkRange(1, 3);

    Person *p = nullptr;
    if (type == 1)
    {
        p = new Entrepreneur();
    }
    else if (type == 2)
    {
        p = new Tourist();
    }
    else if (type == 3)
    {
        p = static_cast<Entrepreneur*>(new Chelnok());
    }
    else
    {
        cout << "Ошибка: неверный выбор. Создаётся обычный турист по умолчанию.\n";
        p = new Tourist();
    }

    int choice;
    cout << "1 - Ввести вручную, 2 - Использовать тестовые данные: ";
    choice = checkRange(1, 2);

    if (choice == 2)
    {
        p->fillTestData();
    }
    else
    {
        p->input();
    }
    
    return p;
}

void createList(Person **&people, int &count)
{
    cout << "Сколько людей создать? ";
    count = checkRange(0, 100);
    delete[] people;
    people = new Person *[count];
    for (int i = 0; i < count; i++)
    {
        cout << "\n--- Ввод данных человека #" << i + 1 << " ---\n";
        people[i] = createPerson();
    }
}

void addPerson(Person **&people, int &count)
{
    int newCount = count + 1;
    auto **temp = new Person *[newCount];
    for (int i = 0; i < count; i++)
        temp[i] = people[i];
    delete[] people;
    people = temp;

    cout << "\n--- Ввод данных нового человека ---\n";
    people[count] = createPerson();
    count = newCount;
}

void printAll(span<Person*> people)
{
    for (const Person* person : people) {
        if (person != nullptr) {
            person->printInfo();
            cout << "\n";
        }
    }
}