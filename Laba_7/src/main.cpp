#include "../hdr/function.h"
#include <iostream>

int main() {
    FileReader fileReader;
    std::string filePath = "docs/data.txt";
    int choice;
    
    std::cout << "Программа для работы с файлом через перегруженный оператор []" << std::endl;
    
    while (true) {
        printMenu();
        std::cin >> choice;
        clearInputBuffer();
        
        switch (choice) {
            case 1:
                handleCreateFile(fileReader, filePath);
                break;
            
            case 2:
                handleWriteString(fileReader);
                break;
            
            case 3:
                handleReadChar(fileReader);
                break;
            
            case 4:
                handleShowFileSize(fileReader);
                break;
            
            case 5:
                std::cout << "Выход из программы..." << std::endl;
                fileReader.closeFile();
                return 0;
            
            default:
                std::cout << "Неверный выбор! Попробуйте снова." << std::endl;
                break;
        }
    }
    
    return 0;
}

