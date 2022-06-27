#include "Person.h"
#include <iostream>

Person::Person(const std::string Name, const std::string Surname, const std::string Pesel, const std::string Address, const Gender Gender)
{
	name = Name;
	surname = Surname;
	pesel = Pesel;
	address = Address;
	gender = Gender;
}

Person::Person()
{
}

Person::~Person()
{
}

std::string Person::GetName()
{
	return name;
}

std::string Person::GetSurname()
{
	return surname;
}

std::string Person::GetPesel()
{
	return pesel;
}

std::string Person::GetAddress()
{
	return address;
}

Gender Person::GetGender()
{
	return gender;
}