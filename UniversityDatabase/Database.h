#pragma once
#include <vector>
#include "Person.h"
#include <iostream>

using People = std::vector<Person>;
class Database
{
private:
	People Persons;
public:
	void AddPerson(const Person newPerson);
	People GetPersons();
	void RemovePersonByPesel(const std::string pesel);
	People SearchBySurname(const std::string surname);
	Person SearchByPesel(const std::string pesel);
	void PrintPeople();
	void PrintPeople(People people);
	void PrintPersonalInformation(Person person);
	void SavePeopletoFile();
	void LoadPeoplefromFile();
};