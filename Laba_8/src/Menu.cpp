#include "../hdr/Menu.h"
#include <limits>
#include <stdexcept>

// Печать списка
void Menu::printList(const DoublyLinkedList<int>& list) {
    std::cout << "Список: ";
    if (list.empty()) {
        std::cout << "(пуст)";
    } else {
        auto it = list.begin();
        const auto endIt = list.end();
        while (it != endIt) {
            std::cout << *it << " ";
            ++it;
        }
    }
    std::cout << std::endl;
    std::cout << "Размер списка: " << list.getSize() << std::endl;
}

// Показать меню
void Menu::showMenu() {
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

// Обработка выбора
void Menu::processChoice(DoublyLinkedList<int>& list, int choice) {
    switch (choice) {
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

// Ручное заполнение списка
void Menu::fillListManually(DoublyLinkedList<int>& list) {
    std::cout << "\n=== Заполнение списка вручную ===" << std::endl;
    
    int value;
    char choice = ' ';
    
    do {
        std::cout << "Введите число для добавления: ";
        if (!(std::cin >> value)) {
            std::cout << "Ошибка ввода! Введите целое число." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        
        std::cout << "Добавить в начало (f) или в конец (b)? [f/b]: ";
        if (!(std::cin >> choice)) {
            std::cout << "Ошибка ввода!" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            choice = ' '; // Инициализируем безопасным значением
        }
        
        if (choice == 'f' || choice == 'F') {
            list.push_front(value);
            std::cout << "Элемент " << value << " добавлен в начало." << std::endl;
        } else {
            list.push_back(value);
            std::cout << "Элемент " << value << " добавлен в конец." << std::endl;
        }
        
        printList(list);
        
        std::cout << "\nДобавить еще элемент? [y/n]: ";
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            choice = 'n'; // По умолчанию выходим из цикла
        }
    } while (choice == 'y' || choice == 'Y');
    
    std::cout << "\nСписок заполнен!" << std::endl;
    printList(list);
}

// Заполнение списка тестовыми данными
void Menu::fillListWithTestData(DoublyLinkedList<int>& list) {
    std::cout << "\n=== Заполнение списка тестовыми данными ===" << std::endl;
    
    // Очищаем список перед заполнением
    list.clear();
    
    // Добавляем тестовые данные
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

// Сортировка списка
void Menu::sortList(DoublyLinkedList<int>& list) {
    std::cout << "\n=== Сортировка списка ===" << std::endl;
    
    if (list.empty()) {
        std::cout << "Список пуст! Нечего сортировать." << std::endl;
        return;
    }
    
    std::cout << "\nИсходный список:" << std::endl;
    printList(list);
    
    char choice;
    std::cout << "\nСортировать по возрастанию (a) или по убыванию (d)? [a/d]: ";
    std::cin >> choice;
    
    if (choice == 'a' || choice == 'A') {
        Algorithms<int>::quickSort(list);
        std::cout << "\nСписок отсортирован по возрастанию:" << std::endl;
    } else {
        Algorithms<int>::quickSort(list, [](const int& a, const int& b) { return a > b; });
        std::cout << "\nСписок отсортирован по убыванию:" << std::endl;
    }
    
    printList(list);
}

// Поиск в списке
void Menu::searchInList(const DoublyLinkedList<int>& list) {
    std::cout << "\n=== Поиск в списке ===" << std::endl;
    
    if (list.empty()) {
        std::cout << "Список пуст! Нечего искать." << std::endl;
        return;
    }
    
    // Создаем отсортированную копию для бинарного поиска
    DoublyLinkedList<int> sortedList = list;
    Algorithms<int>::quickSort(sortedList);
    
    std::cout << "\nОтсортированный список (для бинарного поиска):" << std::endl;
    printList(sortedList);
    
    int value;
    std::cout << "\nВведите элемент для поиска: ";
    if (!(std::cin >> value)) {
        std::cout << "Ошибка ввода!" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }
    
    const DoublyLinkedList<int>& constSortedList = sortedList;
    auto result = Algorithms<int>::binarySearch(constSortedList, value);
    if (result != sortedList.end()) {
        std::cout << "Элемент " << value << " найден в списке!" << std::endl;
    } else {
        std::cout << "Элемент " << value << " не найден в списке." << std::endl;
    }
}

// Удаление определенного элемента
void Menu::deleteElement(DoublyLinkedList<int>& list) {
    std::cout << "\n=== Удаление элемента ===" << std::endl;
    
    if (list.empty()) {
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
    if (!(std::cin >> choice)) {
        std::cout << "Ошибка ввода!" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }
    
    switch (choice) {
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

// Вспомогательная функция: удаление первого элемента
void Menu::deleteFirstElement(DoublyLinkedList<int>& list) {
    if (!list.empty()) {
        const int removed = list.front();
        list.pop_front();
        std::cout << "Элемент " << removed << " удален из начала списка." << std::endl;
    }
}

// Вспомогательная функция: удаление последнего элемента
void Menu::deleteLastElement(DoublyLinkedList<int>& list) {
    if (!list.empty()) {
        const int removed = list.back();
        list.pop_back();
        std::cout << "Элемент " << removed << " удален из конца списка." << std::endl;
    }
}

// Вспомогательная функция: удаление по значению
void Menu::deleteByValue(DoublyLinkedList<int>& list) {
    int value;
    std::cout << "Введите значение элемента для удаления: ";
    if (!(std::cin >> value)) {
        std::cout << "Ошибка ввода!" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }
    
    auto it = list.begin();
    const auto endIt = list.end();
    bool found = false;
    
    while (it != endIt) {
        if (*it == value) {
            list.erase(it);
            std::cout << "Элемент " << value << " удален из списка." << std::endl;
            found = true;
            break;
        }
        ++it;
    }
    
    if (!found) {
        std::cout << "Элемент " << value << " не найден в списке." << std::endl;
    }
}

// Вспомогательная функция: удаление по позиции
void Menu::deleteByPosition(DoublyLinkedList<int>& list) {
    int pos;
    std::cout << "Введите позицию элемента (начиная с 0): ";
    if (!(std::cin >> pos)) {
        std::cout << "Ошибка ввода!" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }
    
    if (pos < 0 || pos >= static_cast<int>(list.getSize())) {
        std::cout << "Неверная позиция! Размер списка: " << list.getSize() << std::endl;
        return;
    }
    
    auto it = list.begin();
    const auto endIt = list.end();
    int currentPos = 0;
    
    while (it != endIt && currentPos < pos) {
        ++it;
        ++currentPos;
    }
    
    if (it != endIt) {
        const int removed = *it;
        list.erase(it);
        std::cout << "Элемент " << removed << " на позиции " << pos << " удален." << std::endl;
    }
}

// Очистка всего списка
void Menu::clearList(DoublyLinkedList<int>& list) {
    std::cout << "\n=== Очистка списка ===" << std::endl;
    
    if (list.empty()) {
        std::cout << "Список уже пуст." << std::endl;
        return;
    }
    
    std::cout << "Текущий список:" << std::endl;
    printList(list);
    
    char confirm;
    std::cout << "\nВы уверены, что хотите очистить весь список? [y/n]: ";
    std::cin >> confirm;
    
    if (confirm == 'y' || confirm == 'Y') {
        list.clear();
        std::cout << "Список очищен!" << std::endl;
    } else {
        std::cout << "Очистка отменена." << std::endl;
    }
}

// Демонстрация операций со списком
void Menu::demonstrateListOperations() {
    std::cout << "\n=== Демонстрация операций со списком ===" << std::endl;
    
    DoublyLinkedList<int> list;
    
    // Добавление элементов
    std::cout << "\n1. Добавление элементов:" << std::endl;
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    list.push_front(5);
    printList(list);
    
    // Вставка элемента
    std::cout << "\n2. Вставка элемента 15 после первого элемента:" << std::endl;
    auto it = list.begin();
    ++it;
    list.insert(it, 15);
    printList(list);
    
    // Удаление элемента
    std::cout << "\n3. Удаление первого элемента:" << std::endl;
    list.pop_front();
    printList(list);
    
    // Доступ к элементам
    std::cout << "\n4. Первый элемент: " << list.front() << std::endl;
    std::cout << "   Последний элемент: " << list.back() << std::endl;
    std::cout << "   Размер списка: " << list.getSize() << std::endl;
}

// Демонстрация итератора
void Menu::demonstrateIterator() {
    std::cout << "\n=== Демонстрация итератора ===" << std::endl;
    
    DoublyLinkedList<int> list;
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    list.push_back(40);
    
    std::cout << "\nОбход списка вперед:" << std::endl;
    auto it = list.begin();
    const auto endIt = list.end();
    while (it != endIt) {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;
    
    std::cout << "\nОбход списка назад:" << std::endl;
    if (!list.empty()) {
        // Создаем временный список для обратного обхода
        DoublyLinkedList<int> reverseList;
        auto forwardIt = list.begin();
        const auto forwardEnd = list.end();
        while (forwardIt != forwardEnd) {
            reverseList.push_front(*forwardIt);
            ++forwardIt;
        }
        auto reverseIt = reverseList.begin();
        const auto reverseEnd = reverseList.end();
        while (reverseIt != reverseEnd) {
            std::cout << *reverseIt << " ";
            ++reverseIt;
        }
    }
    std::cout << std::endl;
}

// Демонстрация бинарного поиска
void Menu::demonstrateSearch() {
    std::cout << "\n=== Демонстрация бинарного поиска ===" << std::endl;
    
    DoublyLinkedList<int> list;
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    list.push_back(40);
    list.push_back(50);
    
    std::cout << "\nОтсортированный список:" << std::endl;
    printList(list);
    
    // Бинарный поиск
    std::cout << "\n1. Бинарный поиск элемента 30:" << std::endl;
    auto result = Algorithms<int>::binarySearch(list, 30);
    if (result != list.end()) {
        std::cout << "   Элемент найден: " << *result << std::endl;
    } else {
        std::cout << "   Элемент не найден" << std::endl;
    }
    
    std::cout << "\n2. Бинарный поиск элемента 40:" << std::endl;
    result = Algorithms<int>::binarySearch(list, 40);
    if (result != list.end()) {
        std::cout << "   Элемент найден: " << *result << std::endl;
    } else {
        std::cout << "   Элемент не найден" << std::endl;
    }
    
    std::cout << "\n3. Бинарный поиск элемента 25 (не существует):" << std::endl;
    result = Algorithms<int>::binarySearch(list, 25);
    if (result != list.end()) {
        std::cout << "   Элемент найден: " << *result << std::endl;
    } else {
        std::cout << "   Элемент не найден" << std::endl;
    }
}

// Демонстрация быстрой сортировки
void Menu::demonstrateSorting() {
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
    
    // Быстрая сортировка по возрастанию
    std::cout << "\n1. Быстрая сортировка (по возрастанию):" << std::endl;
    DoublyLinkedList<int> list1 = list;
    Algorithms<int>::quickSort(list1);
    printList(list1);
    
    // Быстрая сортировка по убыванию
    std::cout << "\n2. Быстрая сортировка (по убыванию):" << std::endl;
    DoublyLinkedList<int> list2 = list;
    Algorithms<int>::quickSort(list2, [](const int& a, const int& b) { return a > b; });
    printList(list2);
}

// Запуск главного меню
void Menu::run() {
    std::cout << "Программа для работы с двухсвязным списком" << std::endl;
    std::cout << "===========================================" << std::endl;
    
    DoublyLinkedList<int> list;
    int choice;
    
    try {
        do {
            showMenu();
            
            if (!(std::cin >> choice)) {
                std::cout << "Ошибка ввода! Введите число." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            
            if (choice != 0) {
                processChoice(list, choice);
            }
            
        } while (choice != 0);
        
        std::cout << "\n=== Программа завершена ===" << std::endl;
    } catch (const std::bad_alloc& e) {
        std::cerr << "Ошибка выделения памяти: " << e.what() << std::endl;
    } catch (const std::ios_base::failure& e) {
        std::cerr << "Ошибка ввода/вывода: " << e.what() << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << "Ошибка выполнения: " << e.what() << std::endl;
    } catch (const std::logic_error& e) {
        std::cerr << "Логическая ошибка: " << e.what() << std::endl;
    }
}
