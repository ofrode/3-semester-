#include "../headers/string.h"

using namespace std;

String::String() : str(nullptr), length(0) {}

String::String(const char *s)
{
    length = strlen(s);
    str = new char[length + 1];
    strcpy(str, s);
}

String::String(const String &other)
{
    length = other.length;
    str = new char[length + 1];
    strcpy(str, other.str);
}

String &String::operator=(const String &other)
{
    if (this != &other)
    {
        delete[] str;

        length = other.length;
        str = new char[length + 1];
        strcpy(str, other.str);
    }
    return *this;
}

String &String::operator+=(const String &other)
{
    size_t newLength = length + other.length;
    char *newStr = new char[newLength + 1];

    strcpy(newStr, str);
    strcat(newStr, other.str);

    delete[] str;
    str = newStr;
    length = newLength;

    return *this;
}

String::~String()
{
    delete[] str;
}