#include "../headers/string.h"
#include <iostream>
#include <cstring>

using namespace std;

void String::freeMemory()
{
    if (data != nullptr)
    {
        delete[] data;
        data = nullptr;
    }
    length = 0;
}

void String::copyFrom(const char *str, int len)
{
    data = new char[len + 1];
    strncpy(data, str, len);
    data[len] = '\0';
    length = len;
}

String::String() : data(new char[1])
{
    data[0] = '\0';
}

String::String(const char *str) : data(nullptr)
{
    if (str != nullptr)
    {
        length = strlen(str);
        data = new char[length + 1];
        strncpy(data, str, length);
        data[length] = '\0';
    }
    else
    {
        data = new char[1];
        data[0] = '\0';
    }
}

String::String(const String &other) : data(nullptr), length(other.length)
{
    if (other.data != nullptr)
    {
        data = new char[length + 1];
        strncpy(data, other.data, length);
        data[length] = '\0';
    }
    else
    {
        data = new char[1];
        data[0] = '\0';
    }
}

String::~String()
{
    freeMemory();
}

String &String::operator=(const char *str)
{
    if (this->data != str)
    {
        freeMemory();
        if (str != nullptr)
        {
            length = strlen(str);
            data = new char[length + 1];
            strncpy(data, str, length);
            data[length] = '\0';
        }
        else
        {
            data = new char[1];
            data[0] = '\0';
            length = 0;
        }
    }
    return *this;
}

String &String::operator=(const String &other)
{
    if (this != &other)
    {
        freeMemory();
        length = other.length;
        if (other.data != nullptr)
        {
            data = new char[length + 1];
            strncpy(data, other.data, length);
            data[length] = '\0';
        }
        else
        {
            data = new char[1];
            data[0] = '\0';
        }
    }
    return *this;
}

String &String::operator+=(const char *str)
{
    if (str != nullptr && str[0] != '\0')
    {
        auto strLen = strlen(str);
        auto *newData = new char[length + strLen + 1];

        if (data != nullptr)
        {
            strncpy(newData, data, length);
            newData[length] = '\0';
        }
        else
        {
            newData[0] = '\0';
        }

        strncat(newData, str, strLen);
        freeMemory();
        data = newData;
        length += strLen;
    }
    return *this;
}

String &String::operator+=(const String &other)
{
    if (other.length > 0 && other.data != nullptr)
    {
        auto *newData = new char[length + other.length + 1];

        if (data != nullptr)
        {
            strncpy(newData, data, length);
            newData[length] = '\0';
        }
        else
        {
            newData[0] = '\0';
        }

        strncat(newData, other.data, other.length);
        freeMemory();
        data = newData;
        length += other.length;
    }
    return *this;
}