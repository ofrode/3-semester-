#pragma once

#include <string>
#include <fstream>

class FileReader {
private:
    std::fstream file;
    std::string filePath;
    bool isOpen;

public:
    FileReader();
    
    ~FileReader();
    
    bool openFile(const std::string& path);
    
    void closeFile();
    
    bool writeString(const std::string& text);
    
    char operator[](size_t position);
    
    size_t getFileSize();
    
    bool isFileOpen() const;
    
    std::string getFilePath() const;
};
