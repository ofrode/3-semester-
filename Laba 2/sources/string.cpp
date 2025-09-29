#include "../headers/string.h"

using namespace std;

String::String() : str(nullptr), length(0) {}

String::String(const char *s) : length(strlen(s))
{
    str = new char[length + 1];
    strncpy(str, s, length);
    str[length] = '\0';
}

String::String(const String &other) : length(other.length)
{
    str = new char[length + 1];
    strncpy(str, other.str, length);
    str[length] = '\0';
}

String &String::operator=(const String &other)
{
    if (this != &other)
    {
        delete[] str;
        length = other.length;
        str = new char[length + 1];
        strncpy(str, other.str, length);
        str[length] = '\0';
    }
    return *this;
}

String &String::operator+=(const String &other)
{
    size_t newLength = length + other.length;
    auto *newStr = new char[newLength + 1];

    strncpy(newStr, str, length);
    strncpy(newStr + length, other.str, other.length + 1);
    newStr[newLength] = '\0';

    delete[] str;
    str = newStr;
    length = newLength;
    return *this;
}

String::~String()
{
    delete[] str;
}