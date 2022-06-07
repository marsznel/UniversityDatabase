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
	Person(std::string Name, std::string Surname, std::string Pesel, std::string Address, Gender Gender);

	~Person();

	void PrintPersonalInformation();

	bool CheckName(std::string Name);
};


