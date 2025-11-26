#include "../hdr/Menu.h"
#include <limits>

void Menu::printList(DoublyLinkedList<int> &list)
{
    std::cout << "Список: ";
    if (list.empty())
    {
        std::cout << "(пуст)";
    }
    else
    {
        for (auto it = list.begin(); it != list.end(); ++it)
        {
            std::cout << *it << " ";
        }
    }
    std::cout << std::endl;
    std::cout << "Размер списка: " << list.getSize() << std::endl;
}

void Menu::showMenu()
{
    std::cout << "\n===========================================" << std::endl;
    std::cout << "           ГЛАВНОЕ МЕНЮ" << std::endl;
    std::cout << "===========================================" << std::endl;
    std::cout << "1. Заполнить список вручную" << std::endl;
    std::cout << "2. Заполнить список тестовыми данными" << std::endl;
    std::cout << "3. Показать список" << std::endl;
    std::cout << "4. Сортировать список" << std::endl;
    std::cout << "5. Поиск элемента в списке" << std::endl;
    std::cout << "6. Удалить определенный элемент" << std::endl;
    std::cout << "7. Очистить весь список" << std::endl;
    std::cout << "8. Демонстрация всех операций" << std::endl;
    std::cout << "0. Выход" << std::endl;
    std::cout << "===========================================" << std::endl;
    std::cout << "Выберите действие: ";
}

void Menu::processChoice(DoublyLinkedList<int> &list, int choice)
{
    switch (choice)
    {
    case 1:
        fillListManually(list);
        break;
    case 2:
        fillListWithTestData(list);
        break;
    case 3:
        std::cout << "\n=== Текущий список ===" << std::endl;
        printList(list);
        break;
    case 4:
        sortList(list);
        break;
    case 5:
        searchInList(list);
        break;
    case 6:
        deleteElement(list);
        break;
    case 7:
        clearList(list);
        break;
    case 8:
        demonstrateListOperations();
        demonstrateIterator();
        demonstrateSearch();
        demonstrateSorting();
        break;
    case 0:
        std::cout << "\nВыход из программы..." << std::endl;
        break;
    default:
        std::cout << "\nНеверный выбор! Попробуйте снова." << std::endl;
        break;
    }
}

void Menu::fillListManually(DoublyLinkedList<int> &list)
{
    std::cout << "\n=== Заполнение списка вручную ===" << std::endl;

    int value;
    char choice = ' ';

    do
    {
        std::cout << "Введите число для добавления: ";
        if (!(std::cin >> value))
        {
            std::cout << "Ошибка ввода! Введите целое число." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        std::cout << "Добавить в начало (f) или в конец (b)? [f/b]: ";
        std::cin >> choice;

        if (choice == 'f' || choice == 'F')
        {
            list.push_front(value);
            std::cout << "Элемент " << value << " добавлен в начало." << std::endl;
        }
        else
        {
            list.push_back(value);
            std::cout << "Элемент " << value << " добавлен в конец." << std::endl;
        }

        printList(list);

        std::cout << "\nДобавить еще элемент? [y/n]: ";
        std::cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    std::cout << "\nСписок заполнен!" << std::endl;
    printList(list);
}

void Menu::fillListWithTestData(DoublyLinkedList<int> &list)
{
    std::cout << "\n=== Заполнение списка тестовыми данными ===" << std::endl;

    list.clear();

    list.push_back(64);
    list.push_back(34);
    list.push_back(25);
    list.push_back(12);
    list.push_back(22);
    list.push_back(11);
    list.push_back(90);
    list.push_back(5);
    list.push_back(77);
    list.push_back(43);

    std::cout << "Список заполнен тестовыми данными!" << std::endl;
    printList(list);
}

void Menu::sortList(DoublyLinkedList<int> &list)
{
    std::cout << "\n=== Сортировка списка ===" << std::endl;

    if (list.empty())
    {
        std::cout << "Список пуст! Нечего сортировать." << std::endl;
        return;
    }

    std::cout << "\nИсходный список:" << std::endl;
    printList(list);

    char choice;
    std::cout << "\nСортировать по возрастанию (a) или по убыванию (d)? [a/d]: ";
    std::cin >> choice;

    if (choice == 'a' || choice == 'A')
    {
        Algorithms<int>::quickSort(list);
        std::cout << "\nСписок отсортирован по возрастанию:" << std::endl;
    }
    else
    {
        Algorithms<int>::quickSort(list, [](const int &a, const int &b)
                                   { return a > b; });
        std::cout << "\nСписок отсортирован по убыванию:" << std::endl;
    }

    printList(list);
}

void Menu::searchInList(DoublyLinkedList<int> &list)
{
    std::cout << "\n=== Поиск в списке ===" << std::endl;

    if (list.empty())
    {
        std::cout << "Список пуст! Нечего искать." << std::endl;
        return;
    }

    DoublyLinkedList<int> sortedList = list;
    Algorithms<int>::quickSort(sortedList);

    std::cout << "\nОтсортированный список (для бинарного поиска):" << std::endl;
    printList(sortedList);

    int value;
    std::cout << "\nВведите элемент для поиска: ";
    if (!(std::cin >> value))
    {
        std::cout << "Ошибка ввода!" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    const DoublyLinkedList<int> &constSortedList = sortedList;
    Iterator<int> result = Algorithms<int>::binarySearch(constSortedList, value);
    if (result != sortedList.end())
    {
        std::cout << "Элемент " << value << " найден в списке!" << std::endl;
    }
    else
    {
        std::cout << "Элемент " << value << " не найден в списке." << std::endl;
    }
}

void Menu::deleteElement(DoublyLinkedList<int> &list)
{
    std::cout << "\n=== Удаление элемента ===" << std::endl;

    if (list.empty())
    {
        std::cout << "Список пуст! Нечего удалять." << std::endl;
        return;
    }

    std::cout << "\nТекущий список:" << std::endl;
    printList(list);

    std::cout << "\nВыберите способ удаления:" << std::endl;
    std::cout << "1. Удалить первый элемент" << std::endl;
    std::cout << "2. Удалить последний элемент" << std::endl;
    std::cout << "3. Удалить элемент по значению" << std::endl;
    std::cout << "4. Удалить элемент по позиции" << std::endl;
    std::cout << "Выбор: ";

    int choice;
    if (!(std::cin >> choice))
    {
        std::cout << "Ошибка ввода!" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    switch (choice)
    {
    case 1:
        deleteFirstElement(list);
        break;
    case 2:
        deleteLastElement(list);
        break;
    case 3:
        deleteByValue(list);
        break;
    case 4:
        deleteByPosition(list);
        break;
    default:
        std::cout << "Неверный выбор!" << std::endl;
        return;
    }

    std::cout << "\nСписок после удаления:" << std::endl;
    printList(list);
}

void Menu::deleteFirstElement(DoublyLinkedList<int> &list)
{
    if (!list.empty())
    {
        int removed = list.front();
        list.pop_front();
        std::cout << "Элемент " << removed << " удален из начала списка." << std::endl;
    }
}

void Menu::deleteLastElement(DoublyLinkedList<int> &list)
{
    if (!list.empty())
    {
        int removed = list.back();
        list.pop_back();
        std::cout << "Элемент " << removed << " удален из конца списка." << std::endl;
    }
}

void Menu::deleteByValue(DoublyLinkedList<int> &list)
{
    int value;
    std::cout << "Введите значение элемента для удаления: ";
    if (!(std::cin >> value))
    {
        std::cout << "Ошибка ввода!" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    bool found = false;
    for (auto it = list.begin(); it != list.end(); ++it)
    {
        if (*it == value)
        {
            list.erase(it);
            std::cout << "Элемент " << value << " удален из списка." << std::endl;
            found = true;
            break;
        }
    }

    if (!found)
    {
        std::cout << "Элемент " << value << " не найден в списке." << std::endl;
    }
}

void Menu::deleteByPosition(DoublyLinkedList<int> &list)
{
    int pos;
    std::cout << "Введите позицию элемента (начиная с 0): ";
    if (!(std::cin >> pos))
    {
        std::cout << "Ошибка ввода!" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    if (pos < 0 || pos >= static_cast<int>(list.getSize()))
    {
        std::cout << "Неверная позиция! Размер списка: " << list.getSize() << std::endl;
        return;
    }

    auto it = list.begin();
    for (int i = 0; i < pos && it != list.end(); ++i)
    {
        ++it;
    }

    if (it != list.end())
    {
        int removed = *it;
        list.erase(it);
        std::cout << "Элемент " << removed << " на позиции " << pos << " удален." << std::endl;
    }
}

void Menu::clearList(DoublyLinkedList<int> &list)
{
    std::cout << "\n=== Очистка списка ===" << std::endl;

    if (list.empty())
    {
        std::cout << "Список уже пуст." << std::endl;
        return;
    }

    std::cout << "Текущий список:" << std::endl;
    printList(list);

    char confirm;
    std::cout << "\nВы уверены, что хотите очистить весь список? [y/n]: ";
    std::cin >> confirm;

    if (confirm == 'y' || confirm == 'Y')
    {
        list.clear();
        std::cout << "Список очищен!" << std::endl;
    }
    else
    {
        std::cout << "Очистка отменена." << std::endl;
    }
}

void Menu::demonstrateListOperations()
{
    std::cout << "\n=== Демонстрация операций со списком ===" << std::endl;

    DoublyLinkedList<int> list;

    std::cout << "\n1. Добавление элементов:" << std::endl;
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    list.push_front(5);
    printList(list);

    std::cout << "\n2. Вставка элемента 15 после первого элемента:" << std::endl;
    auto it = list.begin();
    ++it;
    list.insert(it, 15);
    printList(list);

    std::cout << "\n3. Удаление первого элемента:" << std::endl;
    list.pop_front();
    printList(list);

    std::cout << "\n4. Первый элемент: " << list.front() << std::endl;
    std::cout << "   Последний элемент: " << list.back() << std::endl;
    std::cout << "   Размер списка: " << list.getSize() << std::endl;
}

void Menu::demonstrateIterator()
{
    std::cout << "\n=== Демонстрация итератора ===" << std::endl;

    DoublyLinkedList<int> list;
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    list.push_back(40);

    std::cout << "\nОбход списка вперед:" << std::endl;
    for (auto it = list.begin(); it != list.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "\nОбход списка назад:" << std::endl;
    if (!list.empty())
    {
        DoublyLinkedList<int> reverseList;
        for (auto it = list.begin(); it != list.end(); ++it)
        {
            reverseList.push_front(*it);
        }
        for (auto it = reverseList.begin(); it != reverseList.end(); ++it)
        {
            std::cout << *it << " ";
        }
    }
    std::cout << std::endl;
}

void Menu::demonstrateSearch()
{
    std::cout << "\n=== Демонстрация бинарного поиска ===" << std::endl;

    DoublyLinkedList<int> list;
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    list.push_back(40);
    list.push_back(50);

    std::cout << "\nОтсортированный список:" << std::endl;
    printList(list);

    const DoublyLinkedList<int> &constList = list;

    std::cout << "\n1. Бинарный поиск элемента 30:" << std::endl;
    Iterator<int> result = Algorithms<int>::binarySearch(constList, 30);
    if (result != list.end())
    {
        std::cout << "   Элемент найден: " << *result << std::endl;
    }
    else
    {
        std::cout << "   Элемент не найден" << std::endl;
    }

    std::cout << "\n2. Бинарный поиск элемента 40:" << std::endl;
    result = Algorithms<int>::binarySearch(constList, 40);
    if (result != list.end())
    {
        std::cout << "   Элемент найден: " << *result << std::endl;
    }
    else
    {
        std::cout << "   Элемент не найден" << std::endl;
    }

    std::cout << "\n3. Бинарный поиск элемента 25 (не существует):" << std::endl;
    result = Algorithms<int>::binarySearch(constList, 25);
    if (result != list.end())
    {
        std::cout << "   Элемент найден: " << *result << std::endl;
    }
    else
    {
        std::cout << "   Элемент не найден" << std::endl;
    }
}

void Menu::demonstrateSorting()
{
    std::cout << "\n=== Демонстрация быстрой сортировки ===" << std::endl;

    DoublyLinkedList<int> list;
    list.push_back(64);
    list.push_back(34);
    list.push_back(25);
    list.push_back(12);
    list.push_back(22);
    list.push_back(11);
    list.push_back(90);

    std::cout << "\nИсходный список:" << std::endl;
    printList(list);

    std::cout << "\n1. Быстрая сортировка (по возрастанию):" << std::endl;
    DoublyLinkedList<int> list1 = list;
    Algorithms<int>::quickSort(list1);
    printList(list1);

    std::cout << "\n2. Быстрая сортировка (по убыванию):" << std::endl;
    DoublyLinkedList<int> list2 = list;
    Algorithms<int>::quickSort(list2, [](const int &a, const int &b)
                               { return a > b; });
    printList(list2);
}

void Menu::run()
{
    std::cout << "Программа для работы с двухсвязным списком" << std::endl;
    std::cout << "===========================================" << std::endl;

    DoublyLinkedList<int> list;
    int choice;

    try
    {
        do
        {
            showMenu();

            if (!(std::cin >> choice))
            {
                std::cout << "Ошибка ввода! Введите число." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }

            if (choice != 0)
            {
                processChoice(list, choice);
            }

        } while (choice != 0);

        std::cout << "\n=== Программа завершена ===" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }
}