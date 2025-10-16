#ifndef STAFF_H
#define STAFF_H

#include "Worker.h"

class StaffWorker : public Worker {
private:
    double fixedSalary{};

public:
    StaffWorker() = default;
    double calculateSalary() const override;
    void inputData() override;
    void printInfo() const override;
};

#endif