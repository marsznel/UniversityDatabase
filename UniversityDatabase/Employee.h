#pragma once
#include "Person.h"

class Employee :
    public Person
{
private:
    float earnings;

public:
    Employee(const std::string Name, const std::string Surname, const std::string Pesel, const std::string Address, const Gender Gender, const float earnings);
    ~Employee();

    float GetEarnings();
};
