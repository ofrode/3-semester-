#include "../hdr/FileReader.h"
#include <iostream>
#include <fstream>
#include <cstring>

FileReader::FileReader() : isOpen(false) {
}

FileReader::~FileReader() {
    closeFile();
}

bool FileReader::openFile(const std::string& path) {
    // Закрываем предыдущий файл, если он был открыт
    closeFile();
    
    filePath = path;
    
    // Открываем файл в режиме чтения и записи
    file.open(filePath, std::ios::in | std::ios::out | std::ios::binary);
    
    if (!file.is_open()) {
        // Если файл не существует, создаем его
        file.open(filePath, std::ios::out | std::ios::binary);
        if (file.is_open()) {
            file.close();
            file.open(filePath, std::ios::in | std::ios::out | std::ios::binary);
        }
    }
    
    isOpen = file.is_open();
    return isOpen;
}

void FileReader::closeFile() {
    if (file.is_open()) {
        file.close();
    }
    isOpen = false;
}

bool FileReader::writeString(const std::string& text) {
    if (!isOpen) {
        std::cerr << "Ошибка: файл не открыт!" << std::endl;
        return false;
    }
    
    // Перемещаемся в конец файла для записи
    file.seekp(0, std::ios::end);
    
    // Записываем строку
    file.write(text.c_str(), text.length());
    
    if (file.fail()) {
        std::cerr << "Ошибка при записи в файл!" << std::endl;
        return false;
    }
    
    // Сбрасываем флаги ошибок
    file.clear();
    return true;
}

char FileReader::operator[](size_t position) {
    if (!isOpen) {
        std::cerr << "Ошибка: файл не открыт!" << std::endl;
        return '\0';
    }
    
    // Сохраняем текущую позицию
    std::streampos currentPos = file.tellg();
    
    // Перемещаемся на нужную позицию
    file.seekg(position, std::ios::beg);
    
    if (file.fail() || file.eof()) {
        std::cerr << "Ошибка: позиция " << position << " выходит за пределы файла!" << std::endl;
        file.clear();
        file.seekg(currentPos); // Восстанавливаем позицию
        return '\0';
    }
    
    // Читаем символ
    char ch;
    file.get(ch);
    
    // Восстанавливаем предыдущую позицию
    file.seekg(currentPos);
    
    return ch;
}

size_t FileReader::getFileSize() {
    if (!isOpen) {
        return 0;
    }
    
    // Сохраняем текущую позицию
    std::streampos currentPos = file.tellg();
    
    // Перемещаемся в конец файла
    file.seekg(0, std::ios::end);
    
    // Получаем размер
    std::streampos size = file.tellg();
    
    // Восстанавливаем позицию
    file.seekg(currentPos);
    
    return static_cast<size_t>(size);
}

bool FileReader::isFileOpen() const {
    return isOpen;
}

std::string FileReader::getFilePath() const {
    return filePath;
}

