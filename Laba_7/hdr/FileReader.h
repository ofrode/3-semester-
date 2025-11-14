#pragma once

#include <string>
#include <string_view>
#include <fstream>

class FileReader {
private:
    std::fstream file;
    std::string filePath;
    bool isOpen = false;

public:
    FileReader() = default;
    
    ~FileReader();
    
    bool openFile(std::string_view path);
    
    void closeFile();
    
    bool writeString(const std::string& text);
    
    char operator[](size_t position);
    
    size_t getFileSize();
    
    bool isFileOpen() const;
    
    std::string getFilePath() const;
};

