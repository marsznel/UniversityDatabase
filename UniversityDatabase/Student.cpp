#include "Student.h"

Student::Student(std::string Name, std::string Surname, std::string Pesel, std::string Address, Gender Gender, std::string Index) :
	Person(Name, Surname, Pesel, Address, Gender), index{Index}
{
	index = Index;
}

Student::~Student()
{
}

void Student::PrintPersonalInformation()
{
	Person::PrintPersonalInformation();
	std::cout << index << std::endl;
}

