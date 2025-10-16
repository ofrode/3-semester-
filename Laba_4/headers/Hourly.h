#ifndef HOURLY_H
#define HOURLY_H

#include "Worker.h"

class HourlyWorker : public Worker {
private:
    double hours{};
    double rate{};

public:
    HourlyWorker() = default;
    double calculateSalary() const override;
    void inputData() override;
    void printInfo() const override;
};

#endif