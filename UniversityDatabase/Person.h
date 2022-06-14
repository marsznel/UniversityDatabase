#pragma once
#include <iostream>

enum class Gender : const char
{
	Male = 'M',
	Female = 'F'
};

class Person
{
private:
	std::string name, surname, pesel, address;
	Gender gender;

public:
	Person(const std::string Name, const std::string Surname, const std::string Pesel, const std::string Address, const Gender Gender);

	~Person();

	std::string GetName();

	std::string GetSurname();

	std::string GetPesel();

	std::string GetAddress();

	Gender GetGender();
};


