#ifndef COMMISSION_H
#define COMMISSION_H

#include "Worker.h"

class CommissionWorker : public Worker {
private:
    double sales{};
    double percent{};

public:
    CommissionWorker() = default;
    double calculateSalary() const override;
    void inputData() override;
    void printInfo() const override;
};

#endif