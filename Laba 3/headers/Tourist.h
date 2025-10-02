#pragma once

#include <iostream>
#include <string>
#include "check.h"
#include "Person.h"

class Tourist : virtual public Person
{
protected:
    std::string passportData;
    std::string *crossDates = nullptr;
    std::string *crossCountries = nullptr;
    int crossCount = 0;

public:
    ~Tourist();

    void input() override;
    void fillTestData() override;
    void printInfo() const override;
};