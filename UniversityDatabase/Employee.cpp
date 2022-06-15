#include "Employee.h"

Employee::Employee(const std::string Name, const std::string Surname, const std::string Pesel, const std::string Address, const Gender Gender, const float Earnings) :
	Person(Name, Surname, Pesel, Address, Gender), earnings { Earnings }
{
	earnings = Earnings;
}

Employee::~Employee()
{
}

float Employee::GetEarnings()
{
	return earnings;
}