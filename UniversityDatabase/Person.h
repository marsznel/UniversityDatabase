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
	return gender == Gender::Male ? "Male" : "Female";
}

inline Gender StringToGender(std::string gender)
{
	return gender == "Male" ? Gender::Male : Gender::Female;
}

	class Person
	{
	private:
		std::string name, surname, pesel, address;
		Gender gender;
	public:
		Person(const std::string Name, const std::string Surname, const std::string Pesel, const std::string Address, const Gender Gender);
		Person(std::string pesel) : pesel(pesel) {}
		Person();
		~Person();
		std::string GetName();
		std::string GetSurname();
		std::string GetPesel();
		std::string GetAddress();
		virtual void SetAddress(std::string newAddress);
		Gender GetGender();
		bool operator == (const Person &person);
		bool operator > (const Person person);
		bool Sort(const Person& person1, const Person& person2);
	};

	