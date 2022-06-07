#pragma once
#include "Person.h"

class Student :
   public Person
{
private:
    std::string index;
public:
    Student(std::string Name, std::string Surname, std::string Pesel, std::string Address, Gender Gender, std::string index);
    ~Student();

    void PrintPersonalInformation();

};

