#pragma once

#include <iostream>
#include <string>
#include <utility>
#include "../../Laba_1/headers/check.h"
#include "Person.h"
#include "Tourist.h"
#include "Entrepreneur.h"

class Chelnok : public Entrepreneur, public Tourist
{
private:
    std::string *purchaseAddresses = nullptr;
    int addrCount = 0;

public:
    Chelnok &operator=(const Chelnok &other) = delete;
    Chelnok(Chelnok &&other) noexcept;
    Chelnok &operator=(Chelnok &&other) noexcept;
    ~Chelnok();

    void inputChelnok();
    void input() override;
    void fillTestData() override;
    void printInfoChelnok() const;
    void printInfo() const override;
};