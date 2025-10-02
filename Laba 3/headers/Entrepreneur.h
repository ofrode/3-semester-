#pragma once

#include <iostream>
#include <string>
#include "check.h"
#include "Person.h"

class Entrepreneur : virtual public Person
{
protected:
    std::string licenseNumber = "1";
    std::string registrationAddress = "Null";
    std::string UNN = "123456789";
    std::string *taxDates = nullptr;

    double *taxSums = nullptr;
    int taxCount = 0;

public:
    Entrepreneur() = default;
    Entrepreneur(const Entrepreneur &other);
    ~Entrepreneur() override;

    void input() override;
    void fillTestData() override;
    void printInfo() const override;
};
