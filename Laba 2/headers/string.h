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
    String(const char *s);
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
        char buffer[1024];
        is.getline(buffer, 1024);
        s = String(buffer);
        return is;
    }
};