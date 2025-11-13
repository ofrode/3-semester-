#include "../hdr/function.h"
#include "../hdr/input.h"
#include <stdexcept>
#include <iostream>

using namespace std;

int main() {
    Person* current = nullptr;
    int choice = -1;
    
    do {
        try {
            showMainMenu();
            choice = inputInt("Ваш выбор: ");
            handleChoice(choice, current);
        } catch (const InputError& e) {
            cout << "Неизвестный аргумент: " << e.what() << "\nПопробуйте еще.\n";
        } catch (const out_of_range& e) {
            cout << "Вышел за ограничения: " << e.what() << "\nПопробуйте еще.\n";
        } catch (const system_error& e) {
            cout << "Ошибка в системе: " << e.what() << "\nПопробуйте еще.\n";
        }
    } while (choice != 0);
    
    if (current != nullptr) {
        delete current;
        current = nullptr;
    }
    
    return 0;
    
}