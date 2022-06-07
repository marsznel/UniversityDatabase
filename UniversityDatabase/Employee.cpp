#include "Employee.h"

Employee::Employee(std::string Name, std::string Surname, std::string Pesel, std::string Address, Gender Gender, float Earnings) :
	Person(Name, Surname, Pesel, Address, Gender), earnings { Earnings }
{
	earnings = Earnings;
}

Employee::~Employee()
{
}

void Employee::PrintPersonalInformation()
{
	Employee::PrintPersonalInformation();
	std::cout << earnings << std::endl;
}