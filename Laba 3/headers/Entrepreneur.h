#pragma once

#include <iostream>
#include <string>
#include "check.h"
#include "Person.h"

class Entrepreneur : virtual public Person
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
    Entrepreneur(const Entrepreneur &other) : Person(other), licenseNumber(other.licenseNumber), registrationAddress(other.registrationAddress), UNN(other.UNN),
                                              taxDates(nullptr), taxSums(nullptr), taxCount(other.taxCount)
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

    void inputEntrepreneur();
    void input() override;
    void fillTestData() override;
    void printEntrepreneur() const;
    void printInfo() const override;
};
