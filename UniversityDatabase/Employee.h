#pragma once
#include "Person.h"

class Employee :
    public Person
{
private:
    float earnings;

public:
    Employee(std::string Name, std::string Surname, std::string Pesel, std::string Address, Gender Gender, float earnings);
    ~Employee();

    void PrintPersonalInformation();

};
