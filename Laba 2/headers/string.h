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

    friend std::ostream &operator<<(std::ostream &os, const String &s);
    friend std::istream &operator>>(std::istream &is, String &s);

};