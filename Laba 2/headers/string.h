#pragma once

#include <iostream>
#include <cstring>
class String
{
private:
    char *str;
    size_t length;

public:
    String();
    explicit String(const char *s);
    String(const String &other);

    String &operator=(const String &other);
    String &operator+=(const String &other);

    ~String();

    friend std::ostream &operator<<(std::ostream &os, const String &s)
    {
        os << s.str;
        return os;
    }

    friend std::istream &operator>>(std::istream &is, String &s)
    {
        char buffer[10];
        is.getline(buffer, 10);
        s = String(buffer);
        return is;
    }
};