#pragma once

enum class Etype
{
    LABORANT,
    SECRETARY,
    MANAGER,
    DIRECTOR
};

struct date
{
    int day;
    int month;
    int year;
};

class Employee
{
private:
    int number = 0;
    float salary = 0.0f;
    date hireDate{1, 1, 2000};
    Etype type = Etype::LABORANT;

public:
    Employee() = default;
    void getEmploy();
    void putEmploy() const;
};