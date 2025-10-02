#pragma once

#include <iostream>
#include <string>
#include "check.h"
#include "Person.h"

class Entrepreneur : public Person
{
private:
    std::string licenseNumber = "1";
    std::string registrationAddress = "Null";
    std::string UNN = "123456789";
    std::string *taxDates = nullptr;

    double *taxSums = nullptr;
    int taxCount = 0;

public:
    Entrepreneur() = default;
    Entrepreneur(const Entrepreneur &other) : Person(other), licenseNumber(other.licenseNumber), registrationAddress(other.registrationAddress),
                                              UNN(other.UNN), taxCount(other.taxCount)
    {
        if (taxCount > 0)
        {
            taxDates = new std::string[taxCount];
            taxSums = new double[taxCount];

            for (int i = 0; i < taxCount; ++i)
            {
                taxDates[i] = other.taxDates[i];
                taxSums[i] = other.taxSums[i];
            }
        }
    }
    ~Entrepreneur() override;

    virtual void inputEntrepreneur();
    virtual void input() override;
    virtual void fillTestData() override;
    virtual void printEntrepreneur() const;
    virtual void printInfo() const override;
};
