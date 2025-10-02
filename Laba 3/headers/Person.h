#pragma once

#include <iostream>
#include <string>
#include "check.h"

class Person
{
protected:
    std::string firstName = "1";
    std::string lastName = "1";
    std::string patronymic = "1";
    
    int birthYear = 2000;

public:
    Person() = default;
    virtual void input();
    virtual void fillTestData();
    virtual void printInfo() const;

    virtual ~Person() {}
};