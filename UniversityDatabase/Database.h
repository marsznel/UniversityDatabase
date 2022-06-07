#pragma once
#include <vector>
#include "Person.h"
#include <iostream>


class Database
{
private: 
	std::vector<Person> Persons;

public:
	void AddPerson(Person newPerson);

	std::vector<Person> GetPersons();

	Person SearchByName(std::string Name);
};

