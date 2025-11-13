#ifndef FUNCTION_H
#define FUNCTION_H

#include "FileReader.h"
#include <string>

// Вывод меню программы
void printMenu();

// Очистка буфера ввода
void clearInputBuffer();

// Обработка создания/открытия файла
void handleCreateFile(FileReader& fileReader, std::string& filePath);

// Обработка записи строки в файл
void handleWriteString(FileReader& fileReader);

// Обработка чтения символа по позиции
void handleReadChar(FileReader& fileReader);

// Обработка показа размера файла
void handleShowFileSize(FileReader& fileReader);

#endif // FUNCTION_H

