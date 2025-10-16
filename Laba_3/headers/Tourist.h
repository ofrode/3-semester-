#pragma once

#include <iostream>
#include <string>
#include <utility>
#include "../../Laba_1/headers/check.h"
#include "Person.h"

class Tourist : public Person
{
private:
    std::string passportData = "1";
    std::string *crossDates = nullptr;
    std::string *crossCountries = nullptr;
    int crossCount = 0;

public:

    Tourist &operator=(const Tourist &other) = delete;
    Tourist(Tourist &&other) noexcept;
    Tourist &operator=(Tourist &&other) noexcept;

    ~Tourist();

    void input() override;
    virtual void inputTourist();
    void fillTestData() override;
    virtual void printInfoTourist() const;
    void printInfo() const override;
};