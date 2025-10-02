#pragma once

#include <iostream>
#include <string>
#include "check.h"
#include "Person.h"

class Tourist : public Person
{
private:
    std::string passportData = "1";
    std::string *crossDates = nullptr;
    std::string *crossCountries = nullptr;
    int crossCount = 0;

public:
    Tourist() = default;
    Tourist(const Tourist &other) : Person(other), passportData(other.passportData), crossCount(other.crossCount)
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

    virtual void input() override;
    virtual void inputTourist();
    virtual void fillTestData() override;
    virtual void printInfoTourist() const;
    virtual void printInfo() const override;
};