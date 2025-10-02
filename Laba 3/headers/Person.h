#pragma once

#include <iostream>
#include <string>
#include "check.h"

class Person
{
protected:
    std::string firstName;
    std::string lastName;
    std::string patronymic;
    
    int birthYear;

public:
    virtual void input();
    virtual void fillTestData();
    virtual void printInfo() const;

    virtual ~Person() {}
};