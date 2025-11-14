#include "../hdr/function.h"
#include "../hdr/input.h"
#include <iostream>
#include <stdexcept>

using namespace std;

void showMainMenu()
{
    cout << "\n=== Меню ===\n";
    cout << "1. Создать Человека\n";
    cout << "2. Создать Предпринемателя\n";
    cout << "3. Создать Туриста\n";
    cout << "4. Создать Челнока\n";
    cout << "0. Выйти\n";
}

void handleChoice(int choice, Person *&current)
{
    if (current != nullptr)
    {
        delete current;
        current = nullptr;
    }

    switch (choice)
    {
    case 1:
        current = new Person();
        current->inputData();
        menuPerson(current);
        break;
    case 2:
        current = new Entrepreneur();
        current->inputData();
        menuEntrepreneur(current);
        break;
    case 3:
        current = new Tourist();
        current->inputData();
        menuTourist(current);
        break;
    case 4:
        current = new Chelnok();
        current->inputData();
        menuChelnok(current);
        break;
    case 0:
        break;
    default:
        cout << "Неверный выбор.\n";
    }
}

void menuPerson(Person *&current)
{
    int choice = -1;
    do
    {
        try
        {
            cout << "\n=== Человек ===\n";
            cout << "1. Просмотреть информацию\n";
            cout << "0. Выйти\n";
            choice = inputInt("Ваш выбор: ");

            switch (choice)
            {
            case 1:
                if (current != nullptr)
                {
                    current->printInfo();
                }
                break;
            case 0:
                break;
            default:
                cout << "Неправильный выбор.\n";
            }
        }
        catch (const InputOutOfRange& ex) {
            cout << "Вышел за ограничение: " << ex.what() << ". Попробуйте еще.\n";
        } catch (const InputError& ex) {
            cout << "Не INT: " << ex.what() << ". Попробуйте еще.\n";
        }
        catch (const system_error &e)
        {
            cout << "Ошибка в системе: " << e.what() << "\nПопробуйте еще.\n";
        }

    } while (choice != 0);
}

void menuEntrepreneur(Person *&current)
{
    if (current == nullptr)
        return;

    auto *e = dynamic_cast<Entrepreneur *>(current);
    if (!e)
        return;

    int choice = -1;
    do
    {
        try
        {
            cout << "\n=== Предпринематель ===\n";
            cout << "1. Просмотреть информацию\n";
            cout << "2. Добавить налоговый платеж\n";
            cout << "3. Просмотреть налоговые платежи\n";
            cout << "0. Выйти\n";
            choice = inputInt("Ваш выбор: ");

            switch (choice)
            {
            case 1:
                e->printInfo();
                break;
            case 2:
            {
                Date d;
                d.inputDate();

                float sum = inputPosFloat("Введите сумму платежа: ");
                e->addTaxPayment(d, sum);
                break;
            }
            case 3:
                e->printTaxPayments();
                break;
            case 0:
                break;
            default:
                cout << "Неправильный выбор.\n";
            }
        } catch (const InputOutOfRange& ex) {
            cout << "Вышел за ограничение: " << ex.what() << ". Попробуйте еще.\n";
        } catch (const InputError& ex) {
            cout << "Не INT: " << ex.what() << ". Попробуйте еще.\n";
        }
        catch (const system_error &e)
        {
            cout << "Ошибка в системе: " << e.what() << "\nПопробуйте еще.\n";
        }
    } while (choice != 0);
}

void menuTourist(Person *&current)
{
    if (current == nullptr)
        return;

    auto *t = dynamic_cast<Tourist *>(current);
    if (!t)
        return;

    int choice = -1;
    do
    {
        try
        {
            cout << "\n=== Турист ===\n";
            cout << "1. Просмотреть информацию\n";
            cout << "2. Добавить пересечение границы\n";
            cout << "3. Просмотреть пересечения границы\n";
            cout << "0. Выйти\n";
            choice = inputInt("Ваш выбор: ");

            switch (choice)
            {
            case 1:
                t->printInfo();
                break;
            case 2:
            {
                Date d;
                d.inputDate();

                string country = inputStr("Добавить страну: ");
                t->addBorderCrossing(d, country);
                break;
            }
            case 3:
                t->printBorderCrossings();
                break;
            case 0:
                break;
            default:
                cout << "Неправильный выбор.\n";
            }
       } catch (const InputOutOfRange& ex) {
            cout << "Вышел за ограничение: " << ex.what() << ". Попробуйте еще.\n";
        } catch (const InputError& ex) {
            cout << "Не INT: " << ex.what() << ". Попробуйте еще.\n";
        }
        catch (const system_error &e)
        {
            cout << "Ошибка в системе: " << e.what() << "\nПопробуйте еще.\n";
        }
    } while (choice != 0);
}

void menuChelnok(Person *&current)
{
    if (current == nullptr)
        return;

    auto *s = dynamic_cast<Chelnok *>(current);
    if (!s)
        return;

    int choice = -1;
    do
    {
        try
        {
            cout << "\n=== Челнок ===\n";
            cout << "1. Просмотреть информацию\n";
            cout << "2. Добавить налоговый платеж\n";
            cout << "3. Просмотреть налоговые платежи\n";
            cout << "4. Добавить пересечение границы\n";
            cout << "5. Просмотреть пересечения границы\n";
            cout << "6. Добавить адресс покупки\n";
            cout << "7. Показать адресс закупки\n";
            cout << "0. Выйти\n";
            choice = inputInt("Ваш выбор: ");

            switch (choice)
            {
            case 1:
                s->printInfo();
                break;
            case 2:
            {
                Date d;
                d.inputDate();

                float sum = inputPosFloat("Введите сумму налогов: ");
                s->addTaxPayment(d, sum);
                break;
            }
            case 3:
                s->printTaxPayments();
                break;
            case 4:
            {
                Date d;
                d.inputDate();

                string country = inputStr("Введите страну: ");
                s->addBorderCrossing(d, country);
                break;
            }
            case 5:
                s->printBorderCrossings();
                break;
            case 6:
            {
                string addr = inputStr("Введите адресс покупки: ");
                s->addShoppingAddress(addr);
                break;
            }
            case 7:
                s->printShoppingAddresses();
                break;
            case 0:
                break;
            default:
                cout << "Неправильный выбор.\n";
            }
        } catch (const InputOutOfRange& ex) {
            cout << "Вышел за ограничение: " << ex.what() << ". Попробуйте еще.\n";
        } catch (const InputError& ex) {
            cout << "Не INT: " << ex.what() << ". Попробуйте еще.\n";
        }
        catch (const system_error &e)
        {
            cout << "Ошибка в системе: " << e.what() << "\nПопробуйте еще.\n";
        }
    } while (choice != 0);
}