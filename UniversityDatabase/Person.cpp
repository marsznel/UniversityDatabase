#include <iostream>
#include "Person.h"



Person::Person(std::string Name, std::string Surname, std::string Pesel, std::string Address, Gender Gender)
{
	name = Name;
	surname = Surname;
	pesel = Pesel;
	address = Address;
	gender = Gender; 
}

Person::~Person()
{
}

void Person::PrintPersonalInformation()
{
	std::cout << name << std::endl;
	std::cout << surname << std::endl;
	std::cout << pesel << std::endl;
	std::cout << address << std::endl;
}

bool Person::CheckName(std::string Name)
{
	return Name == name;
}
