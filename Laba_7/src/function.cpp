#include "../hdr/function.h"
#include <iostream>
#include <limits>

void printMenu() {
    std::cout << "\n=== Меню работы с файлом ===" << std::endl;
    std::cout << "1. Создать/открыть файл" << std::endl;
    std::cout << "2. Записать строку в файл" << std::endl;
    std::cout << "3. Прочитать символ по позиции" << std::endl;
    std::cout << "4. Показать размер файла" << std::endl;
    std::cout << "5. Выход" << std::endl;
    std::cout << "Выберите действие: ";
}

void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void handleCreateFile(FileReader& fileReader, std::string& filePath) {
    std::cout << "Введите путь к файлу (или нажмите Enter для использования " << filePath << "): ";
    std::string inputPath;
    std::getline(std::cin, inputPath);
    
    if (!inputPath.empty()) {
        filePath = inputPath;
    }
    
    if (fileReader.openFile(filePath)) {
        std::cout << "Файл успешно открыт/создан: " << filePath << std::endl;
    } else {
        std::cout << "Ошибка при открытии/создании файла!" << std::endl;
    }
}

void handleWriteString(FileReader& fileReader) {
    if (!fileReader.isFileOpen()) {
        std::cout << "Сначала откройте файл (опция 1)!" << std::endl;
        return;
    }
    
    std::cout << "Введите строку для записи в файл: ";
    std::string text;
    std::getline(std::cin, text);
    
    if (fileReader.writeString(text)) {
        std::cout << "Строка успешно записана в файл!" << std::endl;
    } else {
        std::cout << "Ошибка при записи в файл!" << std::endl;
    }
}

void handleReadChar(FileReader& fileReader) {
    if (!fileReader.isFileOpen()) {
        std::cout << "Сначала откройте файл (опция 1)!" << std::endl;
        return;
    }
    
    size_t fileSize = fileReader.getFileSize();
    std::cout << "Размер файла: " << fileSize << " байт" << std::endl;
    std::cout << "Введите позицию символа (0-" << (fileSize > 0 ? fileSize - 1 : 0) << "): ";
    
    size_t position;
    std::cin >> position;
    clearInputBuffer();
    
    if (std::cin.fail()) {
        std::cout << "Ошибка: введите корректное число!" << std::endl;
        return;
    }
    
    char ch = fileReader[position];
    
    if (ch != '\0' || position < fileSize) {
        std::cout << "Символ на позиции " << position << ": '" << ch << "' (код: " << static_cast<int>(ch) << ")" << std::endl;
    }
}

void handleShowFileSize(FileReader& fileReader) {
    if (!fileReader.isFileOpen()) {
        std::cout << "Сначала откройте файл (опция 1)!" << std::endl;
        return;
    }
    
    size_t size = fileReader.getFileSize();
    std::cout << "Размер файла: " << size << " байт" << std::endl;
}

