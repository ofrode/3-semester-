#pragma once

#include <iostream>
#include <string>
#include "check.h"
#include "Person.h"
#include "Tourist.h"
#include "Entrepreneur.h"

class Chelnok : public Entrepreneur, public Tourist
{
private:
    std::string *purchaseAddresses = nullptr;
    int addrCount = 0;

public:
    Chelnok() = default;
    Chelnok(const std::string *addresses, int count);
    Chelnok(const Chelnok &other): Entrepreneur(other),Tourist(other),addrCount(other.addrCount)
    {
        if (addrCount > 0)
        {
            purchaseAddresses = new std::string[addrCount];
            for (int i = 0; i < addrCount; ++i)
            {
                purchaseAddresses[i] = other.purchaseAddresses[i];
            }
        }
    }
    ~Chelnok() override;

    void inputChelnok();
    void input() override;
    void fillTestData() override;
    void printInfoChelnok() const;
    void printInfo() const override;
};