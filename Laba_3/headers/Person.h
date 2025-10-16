#pragma once

#include <iostream>
#include <string>
#include <utility>
#include "../../Laba_1/headers/check.h"

class Person
{
private:
    std::string firstName = "1";
    std::string lastName = "1";
    std::string patronymic = "1";

    int birthYear = 2000;

public:
    Person() = default;
    Person(const Person &other) = default;
    Person(Person&& other) noexcept = default;

    Person& operator=(const Person& other) = default;
    Person& operator=(Person&& other) noexcept = default;
    
    virtual void input();
    virtual void fillTestData();
    virtual void printInfo() const;

    ~Person() = default;
};