#pragma once

#include <iostream>

class String
{
private:
    char *data;
    int length = 0;

    void freeMemory();
    void copyFrom(const char *str, int len);

public:
    String();
    explicit String(const char *str);
    String(const String &other);
    ~String();

    String &operator=(const char *str);
    String &operator=(const String &other);
    String &operator+=(const char *str);
    String &operator+=(const String &other);

    const char *c_str() const { return data; }
    int size() const { return length; }

    friend std::ostream &operator<<(std::ostream &os, const String &str)
    {
        return os << (str.data ? str.data : "");
    }
    friend std::istream &operator>>(std::istream &is, String &str)
    {
        if (std::string temp; is >> temp)
        {
            str = temp.c_str();
        }
        return is;
    }
    friend String operator+(const String& lhs, const String& rhs) {
        String result = lhs;
        result += rhs;
        return result;
    }
    friend String operator+(const String& lhs, const char* rhs) {
        String result = lhs;
        if (rhs != nullptr) {
            result += rhs;
        }
        return result;
    }
    friend String operator+(const char* lhs, const String& rhs) {
        String result;
        if (lhs != nullptr) {
            result = lhs;
        }
        result += rhs;
        return result;
    }
};