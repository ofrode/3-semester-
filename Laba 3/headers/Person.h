#pragma once

#include <iostream>
#include <string>
#include <utility>
#include "../../Laba 1/headers/check.h"

class Person
{
private:
    std::string firstName = "1";
    std::string lastName = "1";
    std::string patronymic = "1";

    int birthYear = 2000;

public:
    Person() = default;
    Person(Person &other) = default;
    Person& operator=(const Person&& other) noexcept;
    
    virtual void input();
    virtual void fillTestData();
    virtual void printInfo() const;

    virtual ~Person() = default;
};