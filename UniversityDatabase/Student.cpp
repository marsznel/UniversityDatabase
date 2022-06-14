#include "Student.h"

Student::Student(const std::string Name, const std::string Surname, const std::string Pesel, const std::string Address, const Gender Gender, const unsigned long Index) :
	Person(Name, Surname, Pesel, Address, Gender), index{Index}
{
	index = Index;
}

Student::~Student()
{
}

