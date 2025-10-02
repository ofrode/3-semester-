#pragma once

#include <iostream>
#include <string>
#include "check.h"
#include "Person.h"

class Tourist : virtual public Person
{
protected:
    std::string passportData = "1";
    std::string *crossDates = nullptr;
    std::string *crossCountries = nullptr;
    int crossCount = 0;

public:
    Tourist() = default;
    Tourist(const Tourist& other);
    ~Tourist() override;

    void input() override;
    void fillTestData() override;
    void printInfo() const override;
};