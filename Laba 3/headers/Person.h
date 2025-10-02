#pragma once

#include <iostream>
#include <string>
#include "check.h"

class Person
{
private:
    std::string firstName = "1";
    std::string lastName = "1";
    std::string patronymic = "1";

    int birthYear = 2000;

public:
    Person() = default;
    Person(const Person &other): firstName(other.firstName),lastName(other.lastName),patronymic(other.patronymic),birthYear(other.birthYear){};
    
    virtual void input();
    virtual void fillTestData();
    virtual void printInfo() const;

    virtual ~Person() = default;
};