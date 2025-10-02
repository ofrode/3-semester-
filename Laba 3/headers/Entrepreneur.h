#pragma once

#include <iostream>
#include <string>
#include "check.h"
#include "Person.h"

class Entrepreneur : virtual public Person
{
protected:
    std::string licenseNumber;
    std::string registrationAddress;
    std::string UNN;
    std::string *taxDates = nullptr;

    double *taxSums = nullptr;
    int taxCount = 0;

public:
    ~Entrepreneur();

    void input() override;
    void fillTestData() override;
    void printInfo() const override;
};
