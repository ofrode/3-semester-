#include "../hdr/FileReader.h"
#include <iostream>
#include <fstream>
#include <string_view>
#include <cstring>

FileReader::~FileReader() {
    closeFile();
}

bool FileReader::openFile(std::string_view path) {

    closeFile();
    
    filePath = path;
    
    file.open(filePath, std::ios::in | std::ios::out | std::ios::binary);
    
    if (!file.is_open()) {
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
    
    file.seekp(0, std::ios::end);
    
    file.write(text.c_str(), text.length());
    
    if (file.fail()) {
        std::cerr << "Ошибка при записи в файл!" << std::endl;
        return false;
    }
    
    file.clear();
    return true;
}

char FileReader::operator[](size_t position) {
    if (!isOpen) {
        std::cerr << "Ошибка: файл не открыт!" << std::endl;
        return '\0';
    }
    
    std::streampos currentPos = file.tellg();
    
    file.seekg(position, std::ios::beg);
    
    if (file.fail() || file.eof()) {
        std::cerr << "Ошибка: позиция " << position << " выходит за пределы файла!" << std::endl;
        file.clear();
        file.seekg(currentPos);
        return '\0';
    }
    
    char ch;
    file.get(ch);
    
    file.seekg(currentPos);
    
    return ch;
}

size_t FileReader::getFileSize() {
    if (!isOpen) {
        return 0;
    }
    
    std::streampos currentPos = file.tellg();
    
    file.seekg(0, std::ios::end);
    
    std::streampos size = file.tellg();
    
    file.seekg(currentPos);
    
    return static_cast<size_t>(size);
}

bool FileReader::isFileOpen() const {
    return isOpen;
}

std::string FileReader::getFilePath() const {
    return filePath;
}


