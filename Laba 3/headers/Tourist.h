#pragma once

#include <iostream>
#include <string>
#include "check.h"
#include "Person.h"

class Tourist : virtual public Person
{
private:
    std::string passportData = "1";
    std::string *crossDates = nullptr;
    std::string *crossCountries = nullptr;
    int crossCount = 0;

public:
    Tourist() = default;
    Tourist(const Tourist &other);
    Tourist(const Tourist &other) : Person(other), passportData(other.passportData), crossDates(nullptr),
                                    crossCountries(nullptr), crossCount(other.crossCount)
    {
        if (crossCount > 0)
        {
            crossDates = new std::string[crossCount];
            crossCountries = new std::string[crossCount];

            for (int i = 0; i < crossCount; ++i)
            {
                crossDates[i] = other.crossDates[i];
                crossCountries[i] = other.crossCountries[i];
            }
        }
    }
    ~Tourist() override;

    void input() override;
    void inputTourist();
    void fillTestData() override;
    void printInfoTourist() const;
    void printInfo() const override;
};