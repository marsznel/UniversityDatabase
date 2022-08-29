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

void Person::SetAddress(std::string newAddress)
{
	address = newAddress;
}

Gender Person::GetGender()
{
	return gender;
}

bool Person::operator == (const Person& person)
{
	return this->pesel == person.pesel;
}

bool Person::operator > (const Person person)
{
	return true;
}

bool Person::Sort(const Person& person1, const Person& person2)
{
	return person1.pesel > person1.pesel;
}