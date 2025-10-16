#include "../headers/string.h"

using namespace std;

size_t my_strlen(const char* s) {
    if (!s) return 0;
    
    size_t len = 0;
    while (s[len] != '\0') {
        len++;
    }
    return len;
}

String::String() : str(nullptr), length(0) {}

String::String(const char *s) : length(my_strlen(s))
{
    str = new char[length + 1];
    if (s && length > 0)
    {
        memcpy(str, s, length + 1);
    }
    str[length] = '\0';
}

String::String(const String &other) : length(other.length)
{
    str = new char[length + 1];
    memcpy(str, other.str, length + 1);
}

String &String::operator=(const String &other)
{
    if (this != &other)
    {
        delete[] str;
        length = other.length;
        str = new char[length + 1];
        memcpy(str, other.str, length + 1);
    }
    return *this;
}

String &String::operator+=(const String &other)
{
    size_t newLength = length + other.length;
    auto *newStr = new char[newLength + 1];

    memcpy(newStr, str, length);
    memcpy(newStr + length, other.str, other.length + 1);

    delete[] str;
    str = newStr;
    length = newLength;
    return *this;
}

String::~String()
{
    delete[] str;
}