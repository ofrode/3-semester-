#ifndef WORKER_H
#define WORKER_H

#include <string>
#include <iostream>

class Worker
{
private:
    std::string name;

public:
    explicit Worker(const std::string &name = "");
    virtual ~Worker() = default;

    void setName(std::string_view newName);
    std::string getName() const;

    virtual double calculateSalary() const = 0;

    virtual void inputData();
    virtual void printInfo() const;
};

#endif