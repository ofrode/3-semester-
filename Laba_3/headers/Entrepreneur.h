#pragma once

#include <iostream>
#include <string>
#include <utility>
#include "../../Laba_1/headers/check.h"
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
    Entrepreneur &operator=(const Entrepreneur &other) = delete;
    Entrepreneur(Entrepreneur &&other) noexcept;
    Entrepreneur &operator=(Entrepreneur &&other) noexcept;

    ~Entrepreneur();

    virtual void inputEntrepreneur();
    void input() override;
    void fillTestData() override;
    virtual void printEntrepreneur() const;
    void printInfo() const override;
};
