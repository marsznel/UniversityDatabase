#pragma once
#include <iostream>

using namespace std;


enum class Gender : const char
{
	Male = 'M',
	Female = 'F'
};

inline std::string GenderToString(Gender gender)
{
	switch (gender)
	{
	case Gender::Male: return "Male";
	case Gender::Female: return "Female";
	}
}

inline Gender StringToGender(std::string gender)
{
	if (gender == "Male")
	{
		return Gender::Male;
	}
	else if (gender == "Female")
	{
		return Gender::Female;
	}
}

	class Person
	{
	private:
		std::string name, surname, pesel, address;
		Gender gender;
	public:
		Person(const std::string Name, const std::string Surname, const std::string Pesel, const std::string Address, const Gender Gender);
		Person();
		~Person();
		std::string GetName();
		std::string GetSurname();
		std::string GetPesel();
		std::string GetAddress();
		void ChangeAddress(std::string newAddress);
		Gender GetGender();
	};