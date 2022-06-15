#pragma once
#include "Person.h"

class Student :
   public Person
{
private:
    unsigned long index;
public:
    Student(const std::string Name, const std::string Surname, const std::string Pesel, const std::string Address, const Gender Gender, const unsigned long index);
    ~Student();

    unsigned long GetIndex()
    {
        return index;
    }
};

