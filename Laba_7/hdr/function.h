#ifndef FUNCTION_H
#define FUNCTION_H

#include "FileReader.h"
#include <string>


void printMenu();
void clearInputBuffer();
void handleCreateFile(FileReader& fileReader, std::string& filePath);
void handleWriteString(FileReader& fileReader);
void handleReadChar(FileReader& fileReader);
void handleShowFileSize(FileReader& fileReader);

#endif

