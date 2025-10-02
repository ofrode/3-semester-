#pragma once

#include <iostream>
#include <string>
#include "check.h"
#include "Tourist.h"
#include "Entrepreneur.h"

class Chelnok : public Entrepreneur, public Tourist
{
private:
    std::string *purchaseAddresses = nullptr;
    int addrCount = 0;

public:
    ~Chelnok();

    void input() override;
    void fillTestData() override;
    void printInfo() const override;
};