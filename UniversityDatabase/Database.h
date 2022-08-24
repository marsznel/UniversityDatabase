#pragma once
#include <vector>
#include "Person.h"
#include <iostream>

using People = std::vector<Person*>;
class Database
{
private:
	People Persons;
	std::string defaultFile = "People.txt";
public:
	void AddPerson(Person* newPerson);
	bool ValidatePesel(const std::string pesel);
	People GetPersons();
	void RemovePersonByPesel(const std::string pesel);
	People SearchBySurname(const std::string surname);
	Person* SearchByPesel(const std::string pesel);
	void ModifyAddressByPesel(const std::string pesel, const std::string newAddress);
	void PrintPeople();
	void PrintPeople(People people);
	void PrintPersonalInformation(Person *person);
	void SavePeopletoFile();
	void LoadPeoplefromFile();
};